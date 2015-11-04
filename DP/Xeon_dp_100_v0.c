#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // memcpy

#include <omp.h>

// #include "SFMT/SFMT.h"

 #include "dragonPole.h"

#define LOOPMAX 10000000

void dragonpoleMain();
int calcBattlePoint(int *selection);

char *int_char(int num[]){
	int i;
	char *str = (char*)malloc(sizeof(char)*ITEM);

	char str_tmp[ITEM] = {0};

	for(i=0; i<ITEM; i++){
        str_tmp[i] = num[i]+'0';
	}

	strncpy( str, str_tmp, ITEM);

	return str;
}

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

	// for (i=0; i<100; i++) printf("%d", select[i]);
	// putchar('\n');
}

int main(void)
{
	int i;
	int point;
	int selection[ITEM];

	int rand_num;

	srand((unsigned)time(NULL));

	dragonpoleMain();

	for (i=0; i<ITEM; i++) {
		selection[i] = 0;
	}

	int all_max_num = 0;
	int all_max_index[ITEM] = {0};
#pragma omp parallel num_threads(1)
// #pragma omp parallel
	{
		int max_index[ITEM] = {0};
		int max_num = 0;
		for (i=0; i<LOOPMAX; i++){
			get_rand(selection);
			point = calcBattlePoint(selection);
			if (max_num < point){
				max_num = point;
				memcpy( max_index, selection, sizeof(int) * ITEM);
				if (all_max_num < point){
					all_max_num = point;
					memcpy( all_max_index, selection, sizeof(int) * ITEM);
				}
			}
		}
		printf("thread : %3d | comb : %s  | point : %d\n", omp_get_thread_num(), int_char(max_index), max_num);
	}

	// Bad coding?
	// all_max_index & all_max_num
	printf("all_max_comb: %s | point : %d\n", int_char(all_max_index), all_max_num);

	return 0;
}
