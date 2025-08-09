#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int a, b, c, d, sel1a, sel1b, sel2a, sel2b;
    int min = 1000000000;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(c==a || d==b) printf("1\n");
    else{
    sel1a = a+1-c; sel1b = abs(0-c);
    sel2a = b+1-d; sel2b = abs(0-b);
    if(sel1a<min) min = sel1a;
    if(sel1b<min) min = sel1b;
    if(sel2a<min) min = sel2a;
    if(sel2b<min) min = sel2b;
    printf("%d\n", min);
    }
}