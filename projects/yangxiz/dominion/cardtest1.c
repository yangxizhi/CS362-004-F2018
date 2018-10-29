#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define TESTCARD "smithy"

int main(){
    
	int seed = 1000;
	int numPlayers = 2;
	int player = 0;
	int player2 = 0;
	int bonus = 0;
	int newCards = 0;
    int discardedCards = 1;
    int extraCoins = 0;
    int shuffledCards = 0;
	int choice_1 = 0;
    int choice_2 = 0;
    int choice_3 = 0;
	int handPos = 0;
    int bonus = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};
	struct gameState G;
	struct gameState G2;
	
	initializeGame(numPlayers, k, seed, &G);
	
	printf("TESTING Smithy:\n");
	printf("check if the player get 3 cards\n");
	memcpy(&G2, & G, sizeof(struct gameState));
    cardEffect(smithy, choice_1, choice_2, choice_3, &G2, 
	handPos, &bonus);
    newCards = 3;
    extraCoins = 0;
    printf("hand count = %d, expected = %d\n", G2.handCount[player], 
	G.handCount[player] + newCards - discardedCards);
    printf("deck count = %d, expected = %d\n", G2.deckCount[player], 
	G.deckCount[player] - newCards + shuffledCards);
    printf("discard count = %d, expected = %d\n", G2.discardCount[player], 
	G.discardCount[player] + discardedCards);
    assert(G2.handCount[player] == G.handCount[player] 
	+ newCards - discardedCards);
    assert(G2.deckCount[player] == G.deckCount[player] 
	- newCards + shuffledCards);
	
	return 0
}	