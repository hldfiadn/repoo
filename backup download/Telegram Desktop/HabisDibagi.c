#include<stdio.h>

int main(){
    int a, b, cnt=0;
    scanf("%d", &a);
    while(a!=-1){
        scanf("%d", &b);
        if(a!=0 && b!=0){
            if(a>b){
                if(a%b == 0) cnt++;
            }
            else{
                if(b%a == 0) cnt++;
            }
        }
        else if(a==0 && b!=0) cnt++;
        else if(a!=0 && b==0) cnt++; 
        scanf("%d", &a);
    }
    printf("%d\n", cnt);
    return 0;
}