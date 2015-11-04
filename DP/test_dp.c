#include <stdio.h>
#include "dragonPole.h"

#define LOOPMAX 1

void dragonpoleMain();
int calcBattlePoint(int *selection);

int main(){
  int i;
  int point;
  int selection[ITEM] = {0,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,1,0,1,1,0,11,1,1,1,1,1,0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,1,1,1};

  dragonpoleMain();

	point = calcBattlePoint(selection);
	printf("num : %d\n", point);
	
  return 0;
}
