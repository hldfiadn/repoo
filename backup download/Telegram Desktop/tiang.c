#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
 
//written by : Muhammad Jundi Fathan
//Timestamp with epoch : 1639820883435
 
int a, b, i, j, k = 2, cek = 0;
char str[21][31];
int arr[31], arr2[31], arr3[21];
 
int main(){
    scanf("%d", &a);
    for (i=0; i<a; i++){
        scanf("%s", str[i]);
    }
    for (i=0; i<a; i++){
        scanf("%d", &arr[i]);
        arr[i]--;
        arr2[i] = arr[i];
    }
    scanf("%d", &b);
    for (i = 1; i < b; i++){
        for (j = 0; j < a; j++)
            arr3[j] = arr2[arr[j]];
        for (j = 0; j < a; j++)
            arr2[j] = arr3[j];
        for (j = 0; j < a; j++)
            if (arr3[j] == j)
                cek++;
        if (cek == a){
            b = (b % k) + 1;
            i = 0;
        }
        k++;
        cek = 0;
    }
    for (i = 0; i < a; i++){
        printf("%s", str[arr2[i]]);
        if (i == a-1) printf("\n");
        else printf(" ");
    }
}