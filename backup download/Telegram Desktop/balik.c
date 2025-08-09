#include<stdio.h>

int main(){
    long int bil, bul=0;

    scanf("%ld", &bil);
    for(;bil>0; bil= bil/10){
        bul = bul*10 + bil%10;
    }
    printf("%ld\n", bul*3);
}