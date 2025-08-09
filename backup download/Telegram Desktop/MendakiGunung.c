#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int main(){
    int a, b, c, cnt=0, tes=0;
    int tinggi1=0, tinggi2=0, pos1=0, pos2=0;
    int curam1=0, curam2=0;
    bool cek=true, turun=true;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
        scanf("%d", &b);
        if(i==0) c=b;
        else if(b>c && (i+1) != a){
            turun=false;
            cek=false;
            cnt+=(b-c);
            c=b;
            tes++;
        }
        else if(b<=c){
            if(turun==false){
                if(tinggi1==0){
                    tinggi1=cnt;
                    curam1=(float)cnt/tes;
                    pos1=i;
                    cnt=0; tes=0;
                    turun=true;
                }
                else if(tinggi1!=0 || (i+1)==a){
                    tinggi2=cnt;
                    curam2=(float)cnt/tes;
                    pos2=i;
                    turun=true;
                    if(tinggi2>tinggi1){
                        tinggi1=tinggi2;
                        curam1=curam2;
                        pos1=pos2;
                    }
                    else if(tinggi2==tinggi1){
                        if(curam2>curam1){
                            curam1=curam2;
                            pos1=pos2;
                        }
                    }
                }
            }
            }
        }
    if(cek) printf("-1\n");
    else printf("%d\n", pos1);
    }
    
    
