#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a, b, c, max=0, cek;
    scanf("%d", &a);
    for(int i=1; i<=a; i++){
        scanf("%d", &b);
        if(b>max){
            max = b;
            cek = 1;
        }
        else if(b==max) cek++;
    }
    printf("%d %d\n", max, cek);
}