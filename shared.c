//Program to write data into shared memory segment
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    void *shared_memory;
    char buff[100];
    int shmid;

    // Create or open the shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Process attached at %p\n", shared_memory);

    // Prompt user to enter data
    printf("Enter some data to write to shared memory: ");
    fgets(buff, 100, stdin);

    // Write data into shared memory
    strcpy((char *) shared_memory, buff);

    printf("You wrote: %s\n", (char *) shared_memory);

    // Detach from the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}


//Program to read data from shared memory segment
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    void *shared_memory;
    int shmid;

    // Get the shared memory segment
    shmid = shmget((key_t)2345, 1024, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    printf("Process attached at %p\n", shared_memory);

    // Read data from shared memory
    printf("Data read from shared memory is: %s\n", (char *) shared_memory);

    // Detach from the shared memory segment
    if (shmdt(shared_memory) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}





....................................

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of the shared memory segment

int main() {
    int shm_id;
    char *shm_addr;
    key_t key = 1234; // Key for the shared memory segment

    // Create or open the shared memory segment
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write data into shared memory
    strcpy(shm_addr, "Hello, Shared Memory!");

    printf("Data written into shared memory: %s\n", shm_addr);

    // Detach from the shared memory segment
    if (shmdt(shm_addr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}



....................................

  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of the shared memory segment

int main() {
    int shm_id;
    char *shm_addr;
    key_t key = 1234; // Key for the shared memory segment

    // Create or open the shared memory segment
    shm_id = shmget(key, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory segment
    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Read data from shared memory
    printf("Data read from shared memory: %s\n", shm_addr);

    // Detach from the shared memory segment
    if (shmdt(shm_addr) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Optionally remove the shared memory segment
    // shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}

