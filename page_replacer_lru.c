#include<stdio.h>

main(){
      int i,j,k,min,rs[25],frame[10],count[10],flag[25],n,fs,pf=0,next=1;
      printf("Enter length of reference string : ");
      scanf("%d",&n);
      printf("Enter reference string : \n");
      for(i=0;i<=n;i++){
          scanf("%d",&rs[i]);
          flag[i]=0;
      }
      printf("Enter the frame size :");
      scanf("%d",&fs);
      for(i=0;i<fs;i++)
      {
          count[i]=0;
          frame[i]=-1;
      }
      printf("\nThe LRU page replcement process is :-\n");
      for(i=0;i<n;i++){
          for(j=0;j<fs;j++){
              if(frame[j]==rs[i]){
              flag[i]=1;
              count[j]=next;
              next++;
              }
          }
          if(flag[i]==0){
              if(i<fs){
                  frame[i]=rs[i];
                  count[i]=next;
                  next++;
              }
              else{
                  min=0;
                  for(j=1;j<fs;j++)
                      if(count[min]>count[j])
                          min=j;
                  frame[min]=rs[i];
                  count[min]=next;
                  next++;
              }
              pf++;
          }
          for(j=0;j<fs;j++)
              printf("%d\t",frame[j]);
          if(flag[i]==0)
              printf("\npf = %d",pf);
          printf("\n");
      }
      printf("no.of page faults = %d\n",pf);
}
