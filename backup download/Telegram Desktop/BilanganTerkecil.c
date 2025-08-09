#include<stdio.h>

int main(){
    int a, kecil, n;
    scanf("%d", &a);
    scanf("%d", &kecil);
    a--;
    while(a>0){
        scanf("%d", &n);
        if(n < kecil) kecil=n;
        a--;
    }
    printf("%d\n", kecil);
    return 0;
}