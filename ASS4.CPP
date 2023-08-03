#include <iostream>
#include <pthread.h>
#include <unistd.h>

#define phloCount 5
#define adityaPandey_21bci0280 25

pthread_mutex_t mutex;
pthread_cond_t cond[phloCount];
enum
{
    THINKING,
    HUNGRY,
    EATING
} state[phloCount];
int iterations[phloCount] = {0};
int totalIterations = 0;

void test(int philID)
{
    if (state[philID] == HUNGRY && state[(philID + 4) % phloCount] != EATING &&
        state[(philID + 1) % phloCount] != EATING)
    {
        state[philID] = EATING;
        std::cout << "\tPhilosopher " << philID << " --------> currently eating." << std::endl;
        pthread_cond_signal(&cond[philID]);
    }
}

void pickup(int philID)
{
    pthread_mutex_lock(&mutex);
    state[philID] = HUNGRY;
    std::cout << "\tPhilosopher " << philID << " --------> waiting for chopstick." << std::endl;
    test(philID);
    if (state[philID] != EATING)
    {
        pthread_cond_wait(&cond[philID], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void putdown(int philID)
{
    pthread_mutex_lock(&mutex);
    state[philID] = THINKING;
    std::cout << "\tPhilosopher " << philID << " ------> put fork down." << std::endl;
    test((philID + 4) % phloCount);
    test((philID + 1) % phloCount);
    pthread_mutex_unlock(&mutex);
}

void *philosopher(void *threadID)
{
    intptr_t philID = reinterpret_cast<intptr_t>(threadID);

    while (true)
    {
        // Thinking
        std::cout << "\tPhilosopher " << philID << " ------> Thinking." << std::endl;
        usleep(rand() % 500000);

        pickup(philID);

        // Eating
        std::cout << "\tPhilosopher " << philID << " ------> Eating." << std::endl;
        usleep(rand() % 500000);

        putdown(philID);

        pthread_mutex_lock(&mutex);
        iterations[philID]++;
        totalIterations++;
        if (totalIterations >= adityaPandey_21bci0280)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t philosophers[phloCount];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < phloCount; ++i)
    {
        pthread_cond_init(&cond[i], NULL);
    }

    for (intptr_t i = 0; i < phloCount; ++i)
    {
        pthread_create(&philosophers[i], NULL, philosopher, reinterpret_cast<void *>(i));
    }

    for (int i = 0; i < phloCount; ++i)
    {
        pthread_join(philosophers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < phloCount; ++i)
    {
        pthread_cond_destroy(&cond[i]);
    }

    return 0;
}
