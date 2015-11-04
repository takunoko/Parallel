#include <stdio.h>


int main(){
	omp_set_num_threads(120);
	printf("Serial num_threads %d | max_threads %d | num_procs %d\n", 
			omp_get_num_threads(), \
			omp_get_max_threads(), \
			omp_get_num_procs());

	return 0;
}
