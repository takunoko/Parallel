#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 31bit + 31bit + 31bit + 7bit
void get_rand(int select[]){
	int rand_num;
	int i, j, s;

	s = 0;
	for (j = 0; j < 3; j++) {
		rand_num = rand();
		for (i=0; i<31; i++, s++){
			select[s] = rand_num % 2;
			rand_num /= 2;
		}
	}
	rand_num = rand();
	for (i = 0; i < 7; i++, s++){
		select[s] = rand_num % 2;
		rand_num /= 2;
	}

	for (i=0; i<100; i++){
		printf("%d", select[i]);
	}
	putchar('\n');
}

int main(){
	int i;

	int select[100];

	for (i = 0; i < 30; i++) {
		get_rand(select);
	}

	return 0;
}
