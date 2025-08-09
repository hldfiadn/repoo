#include<stdio.h>

int main(){
    float x, y, x1, y1, x2, y2, x3, y3;
    float area;
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    area = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1-y2))/2;
    if(area < 0) area *= -1;
    //printf("%f", area);

    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%f %f", &x, &y);
        float A1 = (x*(y2 - y3) + x2*(y3 - y) + x3*(y-y2))/2;
        if(A1 < 0) A1 *= -1;
        float A2 = (x1*(y - y3) + x*(y3 - y1) + x3*(y1-y))/2;
        if(A2 < 0) A2 *= -1;
        float A3 = (x1*(y2 - y) + x2*(y - y1) + x*(y1-y2))/2;
        if(A3 < 0) A3 *= -1;
        //printf("%f %f %f\n", A1, A2, A3);
        if(area == A1 + A2 + A3) printf("DALAM\n");
        else printf("LUAR\n");
    }
}