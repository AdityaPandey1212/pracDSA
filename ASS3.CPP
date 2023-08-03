#include <iostream>
#include <pthread.h>

#define NUM_THREADS 2


int flag[NUM_THREADS];
int turn = 0;

void *threadFunction(void *threadID)
{
    intptr_t tid = reinterpret_cast<intptr_t>(threadID);

    int other = 1 - tid;

    flag[tid] = 1;
    turn = other;

    while (flag[other] == 1 && turn == other)
    {
        // Busy wait
    }

    // Critical section
    std::cout << "Thread " << tid << " is in the critical section." << std::endl;

    // Exit
    flag[tid] = 0;
    //REMAINING / REMAINDER CODE

    return NULL;
}

int main()
{
    std::cout << "ADITYA KR PADNEY 21BCI0280" << std::endl;
    pthread_t threads[NUM_THREADS];

    for (intptr_t i = 0; i < NUM_THREADS; ++i)
    {
        pthread_create(&threads[i], NULL, threadFunction, reinterpret_cast<void *>(i));
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
