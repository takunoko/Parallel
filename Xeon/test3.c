#include <stdio.h>

int static_data = 0;
int main()
{
	int i;
	int dynamic_data = 0;

#pragma omp parallel
	{
		int local = 0;
		for(i=0; i<1000; i++){
			local++;
			dynamic_data++;
			static_data++;
		}
		printf("local : %d\n", local);
	}
	
	printf("dynamic_data : %d\n", dynamic_data);
	printf("static_data  : %d\n", static_data);

	return 0;
}
