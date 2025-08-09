#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int n, a, b, c, d, e, cnt=0, sel=0, pos=0;
    bool cek = false;
    scanf("%d", &n);
    int poskanan=0, poskiri=0;
    int tinggi1=0, tinggi2=0;
    double curam1=0, curam2=0;
    scanf("%d", &a);
    for(int i=1; i<n; i++){
        scanf("%d", &b);
        if(b > a){
            if(i+1 != n){
                cek = true;
                cnt+=(b-a);
                a = b;
                poskanan=i;
                sel++;
            }
        }
        else if(b <= a){
            if(poskiri != poskanan){
                tinggi2 = cnt;
                curam2 = (double)cnt/sel;
                if(tinggi2 > tinggi1){
                    pos = poskiri;
                    tinggi1 = tinggi2;
                    curam1 = curam2;
                }
                else if(tinggi2 == tinggi1 && curam2 > curam1){
                    pos = poskiri;
                    curam1 = curam2;
                }
            }
            poskiri=i; poskanan=i; cnt=0; sel=0;
        }
        if(i+1 == n){
            if(b>a){
                poskanan = i;
                tinggi2 = cnt;
                curam2 = (double)cnt/sel;
                if(tinggi2 > tinggi1){
                    tinggi1 = tinggi2;
                    curam1 = curam2;
                    pos = poskiri;
                }
                else if(tinggi2 == tinggi1 && curam2 > curam1){
                    pos = poskiri;
                    curam1 = curam2;
                }
            }
        }
    }
    if(cek) printf("%d\n", pos);
    else printf("-1\n");
}