#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//written by : Muhammad Jundi Fathan
//Timestamp with epoch : 1639812773255
  
int main(){
    int a, b, c, d, check=true;
    scanf("%d", &a);
    int arr[10][10] = {0};
    scanf("%d %d %d", &b, &c, &d);
    if(b==0){
        if(c==0){
            if(d==0){
                check=false;
            }
        }
    }
    while(check){
        for(int i=b; i<=b+d-1; i++){
            for(int j=c; j<=c+d-1; j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                }
                else arr[i][j] = 0;
            }
        }
        scanf("%d %d %d", &b, &c, &d);
        if(b==0){
            if(c==0){
                if(d==0){
                check=false;
            }
        }
    }
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            printf("%d", arr[i][j]);
            if(j+1 != a) printf(" ");
        }
        printf("\n");
    }
}
