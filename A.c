#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define SEM_KEY 1234
#define SHM_KEY 5678
#define MESSAGE_SIZE 100

// Function to perform semaphore P (wait) operation
void semWait(int semId)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(semId, &sb, 1);
}

// Function to perform semaphore V (signal) operation
void semSignal(int semId)
{
    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(semId, &sb, 1);
}

int main()
{
    key_t semKey, shmKey;
    int semId, shmId;
    pid_t pid;
    char *shmPtr;

    // Create a semaphore set
    semKey = ftok(".", SEM_KEY);
    semId = semget(semKey, 1, IPC_CREAT | 0666);
    if (semId == -1)
    {
        perror("semget");
        exit(1);
    }

    // Initialize the semaphore value to 0
    semctl(semId, 0, SETVAL, 0);

    // Create shared memory segment
    shmKey = ftok(".", SHM_KEY);
    shmId = shmget(shmKey, MESSAGE_SIZE, IPC_CREAT | 0666);
    if (shmId == -1)
    {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment
    shmPtr = shmat(shmId, NULL, 0);
    if (shmPtr == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        semWait(semId);

        printf("Reader-----> Message received (via Semaphore): '%s'\n", shmPtr);

        semSignal(semId);
    }
    else
    {
        strncpy(shmPtr, "Operating Systems Lab", MESSAGE_SIZE);
        printf("\n");
        printf("Writer-----> Sending message '%s' via Semaphore.\n", shmPtr);

        semSignal(semId);

        semWait(semId);
    }

    shmdt(shmPtr);

    if (shmctl(shmId, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(1);
    }

    if (semctl(semId, 0, IPC_RMID) == -1)
    {
        perror("semctl");
        exit(1);
    }

    return 0;
}
