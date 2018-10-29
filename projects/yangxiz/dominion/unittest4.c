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
	int returnVal = 0;
	int choice_1 = 0;
    int choice_2 = 0;
    int choice_3 = 0;
	int handPos = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};
	struct gameState G;
	
	initializeGame(numPlayers, k, seed, &G);
	
	printf("TESTING playCard:\n");
	printf("1.Testing 0 action\n");
    G.numActions = -1;
    returnVal = playCard(0,choice_1,choice_2,choice_3,&G);
    printf("expected -1, actual: %d\n", return_val);
    assert(returnVal == -1);
    G.numActions = 10;
	printf("**************************************************\n");
	printf("2.Testing 0 card\n");
    G.hand[0][handPos] = gold;
    returnVal = playCard(handPos,choice_1,choice_2,choice_3, &G);
    printf("expected: -1, actual: %d\n",return_val);
    assert(returnVal == -1);
	
	return 0;
	
	
}