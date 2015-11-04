#include <stdio.h>


int main(){
	printf("Serial num_threads %d | max_threads %d | num_procs %d\n", 
			omp_get_num_threads(), \
			omp_get_max_threads(), \
			omp_get_num_procs());

	return 0;
}
