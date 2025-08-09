#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>
 
int arr[1000][1000];
 
int main(){
    int a, b, c, temp;
    scanf("%d", &a);
    int kiri = 0, kanan = a-1;
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int baris = 0;
    for(int i=0; i<a; i++){
        temp = arr[baris][kiri];
        arr[baris][kiri] = arr[baris][kanan];
        arr[baris][kanan] = temp;
        baris++; kiri++; kanan--;
    }
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            printf("%d", arr[i][j]);
            if(j+1 != a) printf(" ");
        }
        printf("\n");
    }
 
    //written by : Muhammad Jundi Fathan
    //Timestamp with epoch : 1639807302812
}
