#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
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
msgrcv(msgid, &message, sizeof(message), 1, 0);
printf("Message received: %s\n", message.mtext);
msgctl(msgid, IPC_RMID, NULL);
return 0;
}
