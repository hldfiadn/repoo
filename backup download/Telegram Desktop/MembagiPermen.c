#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

//written by : Muhammad Jundi Fathan
//Timestamp with epoch : 1639820968890
 
int main(){
    int a, b, c, hasil;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        hasil=0;
        scanf("%d", &b);
        for(int j=0; j<b; j++){
            scanf("%d", &c);
            hasil+=c;
        }
        if(hasil%2==0) printf("1\n");
        else printf("0\n");
    }
}