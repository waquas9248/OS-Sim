#include<stdio.h>
main()
{
int pid;
printf("demo of zombie process");
pid=fork();
if(pid==0)
{
printf("\nchild process pid = %d\n",getpid());
printf("\nparent process pid(from child) = %d\n",getppid());
}
else if(pid>0)
{
sleep(5);
printf("\nparent process pid = %d\n\n",getpid());
system("ps -l");
}
else
printf("error in creation");
}
