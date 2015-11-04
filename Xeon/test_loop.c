#include <stdio.h>
#include "test_loop.h"

int static_data = 0;
int main()
{
	long long int i;
	long long int sum=0;

	omp_set_num_threads(120);
#pragma omp parallel for reduction (+:sum)
	for(i=0; i<N; i++){
		sum += i;
	}

	printf("Serial num_threads %d | max_threads %d | num_procs %d\n", 
			omp_get_num_threads(), \
			omp_get_max_threads(), \
			omp_get_num_procs());

	printf("sum : %lld\n", sum);

	return 0;
}
