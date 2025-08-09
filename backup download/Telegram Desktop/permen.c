#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
    int n, t, i, j, k, mid=0, sum=0, key=0;
    scanf("%d", &t);
    for(i=0; i<t; i++){
        scanf("%d", &n);
        int arr[n];
        for(j=0; j<n; j++){
            scanf("%d", &arr[j]);
            mid+=arr[j];
        }
        if(mid%2==1)
            printf("0\n");
        else{
            mid/=2;
            for (j = 0; j < n; j++){
                for(k=j; k < n; k++){
                    sum+=arr[k];
                    if(sum==mid){
                        printf("1\n");
                        key=1;
                        break;
                    }
                    else if(sum>mid){
                        sum-=arr[k];
                    }
                }
                if(key==1)
                    break;
                sum=0;
            }
            if (key == 0)
                printf("0\n");
        }
        key=0;
        mid=0;
    }
    return 0;
}