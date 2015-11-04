#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "SFMT.h"

#define ITEM 100

char *int_char(int num[]){
	int i,j;
	char *str = (char*)malloc(sizeof(char)*ITEM);

	char str_tmp[ITEM] = {0};

	for(i=0, j=0; i<ITEM; i++){
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

int main()
{
    int i;
    sfmt_t sfmt;

    unsigned long long int tmp;

    sfmt_init_gen_rand(&sfmt, (unsigned)time(NULL));  // sfmtを用いた乱数の初期化

    for (i = 0; i < 100; i++) {
        printf("%02llx\n", sfmt_genrand_uint64(&sfmt));
    }

    tmp = sfmt_genrand_uint64(&sfmt);
    printf("%llu\n", tmp);


    int select[ITEM] = {0};
    sfmt_t stmf;


    for (i = 0; i < 30; i++) {
        get_rand(select, &sfmt);
        printf("c : %s\n", int_char(select));
    }

    return 0;
}
