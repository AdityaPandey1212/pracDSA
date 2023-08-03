#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>

#define BUFFER_SIZE 5

std::queue<int> buffer;
sem_t mutex, emptySlots, fullSlots;

void *producer(void *threadID)
{
    long tid = (long)(intptr_t)threadID;

    for (int i = 0; i < 10; ++i)
    {
        int item = i;

        sem_wait(&emptySlots);
        sem_wait(&mutex);

        buffer.push(item);
        std::cout << "Producer " << tid << " produced item: " << item << std::endl;

        sem_post(&mutex);
        sem_post(&fullSlots);
    }

    pthread_exit(NULL);
    return NULL;
}

void *consumer(void *threadID)
{
    long tid = (long)(intptr_t)threadID;

    for (int i = 0; i < 10; ++i)
    {
        sem_wait(&fullSlots);
        sem_wait(&mutex);

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << tid << " consumed item: " << item << std::endl;

        sem_post(&mutex);
        sem_post(&emptySlots);
    }

    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t producers[5], consumers[5];
    long i;

    sem_init(&mutex, 0, 1);
    sem_init(&emptySlots, 0, BUFFER_SIZE);
    sem_init(&fullSlots, 0, 0);

    for (i = 0; i < 5; ++i)
    {
        pthread_create(&producers[i], NULL, producer, (void *)(intptr_t)i);
        pthread_create(&consumers[i], NULL, consumer, (void *)(intptr_t)i);
    }

    for (i = 0; i < 5; ++i)
    {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);

    return 0;
}
