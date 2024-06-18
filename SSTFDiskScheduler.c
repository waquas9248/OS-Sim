#include<stdio.h>
#include<math.h>

int main() {
    int queue[20], n, head, i, j, k, seek = 0, max, diff, min, temp, loc;
    
    printf("Enter the size of queue request\n");
    scanf("%d", &n);
    
    printf("Enter the queue of disk positions to be read\n");
    for(i = 1; i <= n; i++) {
        scanf("%d", &queue[i]);
    }
    
    printf("Enter the initial head position\n");
    scanf("%d", &head);
    
    queue[0] = head;
    
    for(i = 0; i < n; i++) {
        min = 999;
        for(j = i + 1; j <= n; j++) {
            diff = abs(queue[j] - queue[i]);
            if(diff < min) {
                min = diff;
                loc = j;
            }
        }
        temp = queue[i+1];
        queue[i+1] = queue[loc];
        queue[loc] = temp;
    }
    
    for(i = 0; i < n; i++) {
        diff = abs(queue[i+1] - queue[i]);
        seek += diff;
    }
    
    printf("Total seek time is %d\n", seek);
    
    return 0;
}
