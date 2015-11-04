#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dragonPole.h"

#define LOOPMAX 1

void dragonpoleMain();
int calcBattlePoint(int *selection);

void char_int(const char comb[], int selection[]){
	int i;
	for(i=0; i<ITEM; i++){
		selection[i] = (comb[i] - '0');
	}
}

int main(int argc, const char *argv[])
{
  int i;
  int point;
  int selection[ITEM] = {0};

	if(argc != 2){
		puts("command set error. Please command");
		puts("./test_dp.c comb");
		exit(EXIT_FAILURE);
	}

	if(strlen(argv[1]) != ITEM){
		puts("Error not mathc length");
		printf("This program need comb size %d\n", ITEM);
		printf("But, your comb size %d\n", strlen(argv[1]));
		exit(EXIT_FAILURE);
	}

  dragonpoleMain();

	char_int( argv[1], selection);

	point = calcBattlePoint(selection);
	printf("comb: %s\n", argv[1]);
	printf("num : %d\n", point);
	
	return 0;
}
