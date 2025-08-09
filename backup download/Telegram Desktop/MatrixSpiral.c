#include<stdio.h>

int main(){
    int m, n, num;
    int cnt=1;
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i%2 == 0){
                if(j!=0) printf(" %d", cnt%10);
                else printf("%d", cnt%10);
                cnt++;
            }
            else{
                if(j!=0) printf(" %d", num%10);
                else printf("%d", num%10);
                num--;
            }
        }
        if(i%2==0){
            num = cnt + n;
            num--;
        }
        else{
            cnt = num + n;
            cnt++;
        } 
        printf("\n");
    }
}