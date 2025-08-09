#include<stdio.h>

/*
Written by  : Muhammad Jundi Fathan
Timestamp   : 1664350838
*/

int main(){
    int a, b, c;
    int cnt;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        scanf("%d", &b);
        cnt = 1;
        while(b!=-1){
            scanf("%d", &c);
            if(c == b) cnt++;
            else{
                printf("%d(%d)", b, cnt);
                cnt = 1;
            }
            b = c;
        }
        printf("\n");
    }
}