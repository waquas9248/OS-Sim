#include<stdio.h>
#include<string.h>

main()
{
  int pid,a[20],b[20];
  char str[50],buf[50],buf2[50];
  pipe(a);
  pipe(b);
  pid=fork();
  if(pid>0)
  {
    strcpy(str,"welcome to echo server using pipes program");
    write(a[1],str,sizeof(str));
    sleep(5);
    read(b[0],buf2,sizeof(buf2));
    printf("\nresponse from server is : %s\n",buf2);
  }
  else if(pid==0)
  {
    read(a[0],buf,sizeof(buf));
    printf("request from client is : %s\n",buf);
    strcpy(buf,”hello”);
    write(b[1],buf,sizeof(buf));
  }
  else
    printf("error in creation");
}
