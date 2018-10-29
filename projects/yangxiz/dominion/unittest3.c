#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
int main(){
	
    int seed = 1000;
	int numPlayers = 2;
	int bonus = 0;
	int tempCost = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	initializeGame(numPlayers, k, seed, &G);
	printf("TESTING getCost:\n");
	printf("1.Testing cost for different cards\n");
	printf("Cost of copper should be 0\n");
    tempCost = getCost(copper);
    printf("expected 0, actual: %d\n",tempCost);
    assert(tempCost == 0);
	printf("**************************************************\n");
	printf("Cost of council_room should be 5\n");
    tempCost = getCost(council_room);
    printf("expected 5, actual: %d\n",tempCost);
    assert(tempCost == 5);
	printf("**************************************************\n");
	printf("Cost of great_hall should be 3\n");
    tempCost = getCost(great_hall);
    printf("expected 3, actual: %d\n",tempCost);
    assert(tempCost == 3);
	return 0;
}