#include<stdio.h>

int main(){
    int a, kecil, n;
    int cnt = 1;
    scanf("%d", &a);
    scanf("%d", &kecil);
    a--;
    while(a>0){
        scanf("%d", &n);
        if(n < kecil){
            kecil=n;
            cnt = 1;
        }
        else if(n == kecil){
            cnt++; 
        }
        a--;
    }
    printf("%d %d\n", kecil, cnt);
    return 0;
}