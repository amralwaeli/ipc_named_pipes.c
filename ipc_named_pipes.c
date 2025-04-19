#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
int fd;
char *fifo_path = "/tmp/my_fifo";
char message[] = "Hello from sender!";
char buffer[20];
mkfifo(fifo_path, 0666);
fd = open(fifo_path, O_RDWR);
if (fd < 0) {
perror("Opening FIFO failed");
return 1;
}
write(fd, message, sizeof(message));
read(fd, buffer, sizeof(buffer));
printf("Received: %s\n", buffer);
close(fd);
unlink(fifo_path);
return 0;
}
