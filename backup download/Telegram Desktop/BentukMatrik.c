#include<stdio.h>

int main(){
    int k, m, n, num;
    int counter = 0;
    scanf("%d %d %d", &k, &m, &n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(counter >= k){
                if(j!=0) printf(" %d", 0);
                else printf("%d", 0);
            }
            else{
                scanf("%d", &num);
                if(j!=0) printf(" %d", num);
                else printf("%d", num);
            }
            counter++;
        }
        printf("\n");
    }
}