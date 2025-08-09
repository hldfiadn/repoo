#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    while (k%2 == 0) {
        k /= 2;
    }

    if (k == 1) {
        printf("ya");
    }
    else {
        printf("bukan");
    }

    return 0;
}