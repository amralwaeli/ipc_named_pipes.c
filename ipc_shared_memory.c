#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
memcpy(shm, "Hello from shared memory!", 25);
sleep(20); // sleep 20 seconds before the message is terminated
shmdt(shm);
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
