#include<stdio.h>

/*
Written by  : Muhammad Jundi Fathan
Timestamp   : 1664350850
*/

int main(){
    long int num, nilai, c;
    nilai = 0;
    scanf("%d", &num);

    while(num){
    
    switch (num){
    case 1:
        scanf("%ld", &nilai);
        break;
    case 2:
        scanf("%ld", &c);
        nilai += c;
        break;
    case 3:
        scanf("%ld", &c);
        nilai -= c;
        break;
    case 4:
        scanf("%ld", &c);
        nilai *= c;
        break;
    case 5:
        scanf("%ld", &c);
        nilai /= c;
        break;
    case 9:
        printf("%ld\n", nilai);
        break;
    case 0:
        return 0;
        break;
    }
    scanf("%ld", &num);
    
    }
    return 0;
}