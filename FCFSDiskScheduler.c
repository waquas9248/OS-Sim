#include<stdio.h> 
#include<math.h> 
int main() {
int queue[20],n,head,i,j,k,seek=0,max,diff; 
float avg; printf ("Enter the size of queue request\n");
scanf("%d",&n); printf ("Enter the queue of disk positions to be read\n"); 
for(i=1;i<=n;i++) 
  scanf("%d",&queue[i]);
printf("Enter the initial head position\n"); 
scanf("%d",&head);
queue[0]=head; 
for(i=0;i<n;i++) {
  diff=abs(queue[i+1]-queue[i]); 
  seek+=diff;
  printf("Disk head moves from %d to %d with seek %d\n",queue[i],queue[i+1],diff);
}  
printf("Total seek time is %d\n",seek); 
}
