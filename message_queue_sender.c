#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
struct msgbuf {
long mtype;
char mtext[100];
};
int main() {
key_t key;
int msgid;
key = ftok("msgqfile", 65);
msgid = msgget(key, 0666 | IPC_CREAT);
struct msgbuf message;
message.mtype = 1;
strcpy(message.mtext, "Hello from the background sender!");
msgsnd(msgid, &message, sizeof(message), 0);
printf("Message sent: %s\n", message.mtext);
return 0;
}
