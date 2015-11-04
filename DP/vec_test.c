#include <stdio.h>
#include <omp.h>

#define ITEM 1000000000

int main(void){
    int a[ITEM] = {0};
    int b[ITEM] = {0};
    int c[ITEM];

    int i;

#pragma omp simd
    for (i = 0; i < ITEM; i++) {
        c[i] = a[i] + b[i];
    }

    return 0;
}
