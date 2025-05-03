#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for fork()
#include <sys/wait.h> // for wait()
#include <sys/types.h> // for pid_t

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("CHILD: Hello from the child process! My PID is %d.\n", getpid());
        printf("CHILD: I will sleep for 2 seconds...\n");
        sleep(2); // Simulate some work
        printf("CHILD: Exiting now.\n");
        exit(0); // Child exits
    } else {
        // Parent process
        printf("PARENT: Hello from the parent process! My PID is %d.\n", getpid());
        printf("PARENT: I created a child with PID %d.\n", pid);
        printf("PARENT: Waiting for the child process to finish...\n");

        // Wait for the child process to terminate
        wait(NULL); // Wait for any child

        printf("PARENT: Child process %d finished. Parent exiting.\n", pid);
    }

    return 0;
}
