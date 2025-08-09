#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    long long int a, b, cnt;
    scanf("%lld", &a);
    for(int i=1; i<=a; i++){
        scanf("%lld", &b);
        cnt=1 + 2*(b/2) + 3*((b-1)/2);
        printf("%lld\n", cnt);
    }
}