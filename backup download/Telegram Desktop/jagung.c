#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
 
//written by : Muhammad Jundi Fathan
//Timestamp with epoch : 1639818313181
 
int main(){
    int a, b, c, cek, maks = 0;
    scanf("%d %d", &a, &b);
    int arr[a][a];
    c = b-1;
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=1; i<a; i++){
        arr[0][i] = arr[0][i-1] + arr[0][i];
        arr[i][0] = arr[i-1][0] + arr[i][0];
    }
    for(int i=1; i<a; i++){
        for(int j=1; j<a; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
        }
    }
    for(int i=c; i<a; i++){
        for(int j=c; j<a; j++){
            cek = arr[i][j];
            if(i>c && j>c) cek = arr[i][j] - arr[i-b][j] - arr[i][j-b] + arr[i-b][j-b];
            else if(i>c) cek = arr[i][j] - arr[i-b][j];
            else if(j>c) cek = arr[i][j] - arr[i][j-b];
            if(maks < cek) maks = cek;
        }
    }
    printf("%d\n", maks);
}