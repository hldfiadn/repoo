#include<stdio.h>

/*
Written by  : Muhammad Jundi Fathan
Timestamp   : 1664350821
*/

int main(){
    int a, b, c;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        for(int j=0; j<=i; j++){
            if(i==0) printf("*");
            else if(j==i) printf("*");
            else if(j==0) printf("*");
            else if(i+1 == a) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}