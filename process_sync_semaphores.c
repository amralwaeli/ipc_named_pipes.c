#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
sem_t *semaphore;
pid_t pid;
char *sem_name = "/my_semaphore";
semaphore = sem_open(sem_name, O_CREAT | O_EXCL, 0666, 0);
if (semaphore == SEM_FAILED) {
perror("Creating semaphore failed");
return 1;
}
pid = fork();
if (pid < 0) {
perror("Fork failed");
return 1;
} else if (pid == 0) {
printf("Child waiting for semaphore\n");
sem_wait(semaphore);
printf("Child acquired semaphore\n");
// Critical section starts
sleep(5);
// Critical section ends
sem_post(semaphore);
} else {
sleep(1);
printf("Parent releasing semaphore\n");
sem_post(semaphore);
wait(NULL);
}
sem_close(semaphore);
sem_unlink(sem_name);
return 0;
}
