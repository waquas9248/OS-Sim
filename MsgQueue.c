#include<string.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
main()
{
int pid,msqid;
char str[50],buf[50];
msqid=msgget((key_t)8,IPC_CREAT|0600);
pid=fork();
if(pid>0)
{
strcpy(str,"welcome to message queue");
msgsnd(msqid,str,sizeof(str),0);
}
else if(pid==0)
{
msgrcv(msqid,buf,sizeof(buf),0,0);
printf("msg received is : %s\n",buf);
}
else
printf("error in creation");
}
