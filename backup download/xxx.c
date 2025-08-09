#include<stdio.h>

int main () {
    char n[150];

    for (int i=0; i<120; i++) {
        scanf("%c", &n[i]);
    }

    for (int i=1; i<120; i++) {
        if (n[i]="X"){
            printf("1");
        }
        else if (n[i]= ".") {
            printf("0");
        }
    }
}