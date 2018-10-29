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
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	initializeGame(numPlayers, k, seed, &G);
	
	printf("TESTING buyCard:\n");
	printf("1.Testing no enough buy\n");
	G.numBuys = -1;
    int returnVal = buyCard(village, &G);
    printf("expected -1, actual: %d\n", returnVal);
    assert(returnVal == -1);
    G.numBuys = 1;
	printf("**************************************************\n");
	printf("2.Testing no enough card available\n");
	G.supplyCount[village] = 0;
	returnVal=buyCard(village, &G);
	printf("Result should be -1, actual: %d\n", returnVal);
    assert(returnVal == -1);
    G.supplyCount[village] = 10;
	printf("**************************************************\n");
	printf("3.Test succcess buy\n");
	int begCoins = G.coins;
    G.numBuys = 10;
    int begBuys = G.numBuys;
    buyCard(village, &G);
    printf("Test coins left after buy village.\n");
    printf("expected coins 7, actual: %d\n", G.coins);
    assert(G.coins == 7);
    printf("Chenck the buy number left\n");
    printf("expected buys 9, actual: %d\n", G.numBuys);
    assert(G.numBuys == 9);
	return 0;
}