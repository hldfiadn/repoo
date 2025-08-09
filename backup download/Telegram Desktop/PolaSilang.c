#include<stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int m, n, ci, cj;
        scanf("%d %d %d %d", &m, &n, &ci, &cj);
        for(int j=1; j<=m; j++){
            for(int k=1; k<=n; k++){
                if(j==ci && k==cj) printf("*");
                else if((j-k) == (ci-cj) || (j+k) == (ci+cj)) printf("*");
                else printf(".");
            }
            printf("\n");
        }
    }
}