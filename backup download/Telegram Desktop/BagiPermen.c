#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdlib.h>

//written by : Muhammad Jundi Fathan
//Timestamp with epoch : 1639821095409

bool cariSubset(int arr[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;

    if (arr[n - 1] > sum)
        return cariSubset(arr, n - 1, sum);

    return cariSubset(arr, n - 1, sum)
           || cariSubset(arr, n - 1, sum - arr[n - 1]);
}
bool partisi(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    return cariSubset(arr, n, sum / 2);
}
 
int arr[1001];

int main(){
    int a, b, c;
    scanf("%d", &a);
    for(int dor; dor<a; dor++){
        scanf("%d", &b);
        for(int i=0; i<a; i++){
            scanf("%d", arr[i]);
        }
        int n = b / sizeof(arr[0]);

        if (partisi(arr, n) == true) printf("1\n");
        else printf("0\n");
    }
}