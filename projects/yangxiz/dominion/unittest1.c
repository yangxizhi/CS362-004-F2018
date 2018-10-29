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
	initializeGame(numPlayers, k, seed, &G3);
	
	printf("TESTING initializeGame:\n");
	printf("1.check card number when 2 players\n");
	printf("number of players is 2, actual: %d\n", G.numPlayers);
    assert(G.numPlayers == 2);
    printf("number of curse cards is 10, actual: %d\n", G.supplyCount[curse]);
    assert(G.supplyCount[curse] == 10);
    printf("number of estate cards is 8, actual: %d\n", G.supplyCount[estate]);
    assert(G.supplyCount[estate] == 8);
    printf("number of province cards is 8, actual: %d\n", G.supplyCount[province]);
    assert(G.supplyCount[province] == 8);
	printf("**************************************************\n");
	printf("2.check card number when 3 players\n");
	printf("number of players is 2, actual: %d\n", G3.numPlayers);
    assert(G3.numPlayers == 2);
    printf("number of curse cards is 20, actual: %d\n", G3.supplyCount[curse]);
    assert(G3.supplyCount[curse] == 20);
    printf("number of duchy cards is 12, actual: %d\n", G3.supplyCount[duchy]);
    assert(G3.supplyCount[duchy] == 12);
    printf("number of province cards is 12, actual: %d\n", G3.supplyCount[province]);
    assert(G3.supplyCount[province] == 12);
	printf("**************************************************\n");
	printf("3.check number of resources cards\n");
	printf("number of silver in game should be 40, actual: %d\n" ,
        G.supplyCount[silver] == 40);
    assert(G.supplyCount[silver] == 40);
    printf("number of gold in game should be 30, actual: %d\n", 
        G.supplyCount[gold] == 30);
		return 0;
}
