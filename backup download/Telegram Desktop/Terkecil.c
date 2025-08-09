#include<stdio.h>

int main(){
    int a, b, c;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        int iter;
        int min;
        scanf("%d", &iter);
        scanf("%d", &min);
        for(int j=1; j<iter; j++){
            int bilangan;
            scanf("%d", &bilangan);
            if(bilangan < min) min = bilangan;
        }
        printf("%d\n", min);
    }
}