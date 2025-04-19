#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#define SHM_SIZE 1024
int main() {
int shmid;
key_t key;
char *shm, *s;
key = ftok("shmfile", 65);
shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
shm = shmat(shmid, NULL, 0);
// Read the message from the shared memory segment
printf("Message from shared memory: %s\n", shm);
shmdt(shm);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
