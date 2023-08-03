#include <iostream>
#include <queue>
#include <pthread.h>
#include <semaphore.h>
#include <cstdint> 

#define NUM_READERS 3
#define NUM_WRITERS 2
#define NUM_READS 5
#define NUM_WRITES 3

int data = 0;         
int readersCount = 0; 
sem_t mutex, wrt;
void *reader(void *threadID)
{
    intptr_t tid = reinterpret_cast<intptr_t>(threadID); // Cast to intptr_t

    for (int i = 0; i < NUM_READS; ++i)
    {
        sem_wait(&mutex);
        readersCount++;
        if (readersCount == 1)
        {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        std::cout << "Reader " << tid << " reads data: " << data << std::endl;
        sem_wait(&mutex); 
        readersCount--;
        if (readersCount == 0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);
    }
    return NULL; 
}

void *writer(void *threadID)
{
    intptr_t tid = reinterpret_cast<intptr_t>(threadID); 
    for (int i = 0; i < NUM_WRITES; ++i)
    {
        sem_wait(&wrt); 
        data = tid;
        std::cout << "Writer " << tid << " writes data: " << data << std::endl;

        sem_post(&wrt); 
    }

    return NULL; 
}

int main()
{

    std::cout << "ADITYA KR PADNEY 21BCI0280" << std::endl;

    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    sem_init(&mutex, 0, 1); 
    sem_init(&wrt, 0, 1);  
    for (intptr_t i = 0; i < NUM_READERS; ++i)
    {
        pthread_create(&readers[i], NULL, reader, reinterpret_cast<void *>(i)); // Cast to void*
    }

    for (intptr_t i = 0; i < NUM_WRITERS; ++i)
    {
        pthread_create(&writers[i], NULL, writer, reinterpret_cast<void *>(i)); // Cast to void*
    }

    for (int i = 0; i < NUM_READERS; ++i)
    {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; ++i)
    {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex); 
    sem_destroy(&wrt);

    return 0;
}
