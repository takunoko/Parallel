#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // memcpy

#include <omp.h>

#include "SFMT/SFMT.h"

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

// 64bit + 36bit
void get_rand(int select[], sfmt_t *sfmt){
	unsigned long int rand_num;
	int i, s;

    rand_num = sfmt_genrand_uint64(sfmt);

    s=0;
    for (i=0; i<64; i++, s++){
        select[s] = rand_num % 2;
        rand_num /= 2;
    }

    rand_num = sfmt_genrand_uint64(sfmt);

    for (i = 0; i < 36; i++, s++) {
        select[s] = rand_num % 2;
        rand_num /= 2;
    }
}

int main(void)
{
	int i;
	int point;
	int selection[ITEM];

    sfmt_t sfmt;

    sfmt_init_gen_rand(&sfmt, (unsigned)time(NULL));  // sfmtを用いた乱数の初期化

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
        sfmt_t sfmt_2; // 並列した部分で値をコピーする何かがあった気がする
        sfmt_2 = sfmt; // 本を見て探す
		for (i=0; i<LOOPMAX; i++){
			get_rand(selection, &sfmt_2);
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
