#include <stdio.h>
#include "test_loop.h"

int static_data = 0;
int main()
{
	long long int i;
	long long int sum=0;

	for(i=0; i<N; i++){
		sum += i;
	}
	printf("sum : %lld\n", sum);

	return 0;
}
