#include <stdio.h>

int main()
{
	int i;
	int a = 0;

#pragma omp parallel for reduction (+:a)
	for(i=0; i<1000; i++)
		a++;
	
	printf("%d\n", a);
	
	return 0;
}
