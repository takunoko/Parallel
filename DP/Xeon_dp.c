#include <stdio.h>

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <omp.h>

#include "dragonPole.h"

// #define LOOPMAX 1024
#define LOOPMAX 1000000
#define MAX_NUM 1073741824

void dragonpoleMain();
int calcBattlePoint(int *selection);

void int_bit(int num, int out[]){
    int i,j;
    for(i=0; num != 0; num = num /2, i++){
        out[i] = num % 2;
    }
}

void int_pri_bit(int num){
    int i;
    for(i=0; i<ITEM; num = num /2, i++){
        printf("%d",num%2);
    }
}

char *int_char(int num){
	int i;
	char *str = (char*)malloc(sizeof(char)*ITEM);

	char str_tmp[ITEM] = {'\0'};

	for(i=0; i<ITEM; i++){
        str_tmp[i] = (num%2)+'0';
		num /= 2;
	}

	strncpy( str, str_tmp, ITEM);

	return str;
}

int get_rand(void){
    return rand()%MAX_NUM;
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

    printf("hello");

    int all_max_num = 0;
    int all_max_index = 0;
    // #pragma omp parallel num_threads(4)
#pragma omp parallel
    {
        long long int max_index = 0;
        long long int max_num = 0;
        for (i=0; i<LOOPMAX; i++){
            rand_num = get_rand();
            int_bit( rand_num, selection);
            point = calcBattlePoint(selection);

            if (max_num < point){
                max_num = point;
                max_index = rand_num;
                if (all_max_num < point){
                    all_max_num = point;
                    all_max_index = rand_num;
                }
            }
        }
        printf("thread : %3d | comb : %s  | point : %lld\n", omp_get_thread_num(), int_char(max_index), max_num);
    }
    printf("world");

    // Bad coding?
    // all_max_index & all_max_num
    printf("all_max_comb: %s | point : %lld\n", int_char(all_max_index), all_max_num);

    return 0;
}
