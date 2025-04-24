#include<stdio.h>

main()
{
    int pid;
    printf("\ndemo of orphan process\n");
    pid=fork();
    if(pid==0){
        sleep(10);
        printf("\nchild process pid = %d",getpid());
        printf("\nparent process pid(from child) = %d\n",getppid());
    }
    else if(pid>0)
        printf("\nparent process pid = %d\n",getpid());
    else
        printf("error in creation\n");
}
