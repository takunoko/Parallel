#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ITEM 1000000

int calc_vec(int a[], int b[]){
	unsigned long long int sum=0;
	int i;

#pragma omp parallel for reduction(+:sum)
	for (i = 0; i < ITEM; i++) {
		sum += a[i] * b[i];
	}

	return sum;
}

int main(void){
	int a[ITEM] = {0};
	int b[ITEM] = {0};
	int i;

	for (i=0; i < ITEM; i++) {
		a[i] = rand()%10000;
		b[i] = rand()%10000;
	}

	for (i = 0; i < 10000000000; i+=1000000000) {
		printf("sum: %d\n", calc_vec(a,b));
	}

	return 0;
}
