#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;

	srand((unsigned)time(NULL));

#pragma omp parallel
	{
		int local = 0;
		int max_rand=0;
		for(i=0; i<1000; i++){
			max_rand = rand()%100000;
		}
		printf("max_rand : %d\n",max_rand);
	}

	return 0;
}
