#include<stdio.h>
main()
{
int i,n,a[50],frame[10],fs,k,avail,count=0,loc;
printf("Enter the length of ref string : ");
scanf("%d",&n);
printf("Enter reference string : \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter frame size : ");
scanf("%d",&fs);
for(i=0;i<fs;i++)
frame[i]=-1;
loc=0;
printf("\nref_str\tpageframe\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
avail=0;
for(k=0;k<fs;k++)
{
if(frame[k]==a[i])
avail=1;
}
if(avail==0)
{
frame[loc]=a[i];
loc=(loc+1)%fs;
count++;
for(k=0;k<fs;k++)
printf("%d\t",frame[k]);
}
printf("\n");
}
printf("no.of page faults = %d\n",count);
}
