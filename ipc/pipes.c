#include<stdio.h>
#include<string.h>

main()
{
    int pid,a[20];
    char str[30],buf[30];
    pipe(a);
    pid=fork();
    if(pid > 0){
        strcpy(str,"welcome to ipc using pipes");
        write(a[1],str,sizeof(str));
    }
    else if(pid==0){
        read(a[0],buf,sizeof(buf));
        printf("msg received by child is %s\n",buf);
    }
    else
        printf("error in creation");
}
