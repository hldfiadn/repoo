#include<stdio.h>

int main(){
    int a, b, c, cnt=0;
    int sum;
    scanf("%d %d", &a, &b);
    int arr[a];
    for(int i=0; i<a; i++){
        scanf("%d", &arr[i]);
        if(arr[i]>=b) cnt++;
    }
    for(int i=0; i<a; i++){
        int cek = 1;
        sum = 0;
        sum+=arr[i];
        for(int j=i+1; j<a; j++){
            sum+=arr[j];
            cek++;
            if(sum/cek >= b) cnt++;
        }
    }
    printf("%d\n", cnt);
}