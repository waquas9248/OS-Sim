#include<stdio.h>
#include<pthread.h>
void *runner();
main()
{
int i;
printf("demo of thread\n");
pthread_t tid;
pthread_create(&tid,NULL,runner,0);
pthread_join(tid,NULL);
for(i=0;i<5;i++)
{
printf("inside main\n");
sleep(1);
}
}
void *runner()
{
int i;
for(i=0;i<5;i++)
{
//sleep(2);
printf("inside thread\n");
sleep(1);
}
pthread_exit(0);
}
