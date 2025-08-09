#include<stdio.h>

int main(){
    int n, k, bil;
    int cnt = 0;
    double avg = 0;
    scanf("%d %d", &n, &k);
        for(int i=1; i<=n; i++){
            scanf("%d", &bil);
            if(i%k==0){
                avg += bil;
                cnt++;
            }
        }
    // printf("%lf %d\n", avg, cnt);
    if(k>n || n==0 || k==0) printf("%.2f", 0);
    else{
        avg /= (n/k);
        printf("%.2lf\n", avg);
    }
}