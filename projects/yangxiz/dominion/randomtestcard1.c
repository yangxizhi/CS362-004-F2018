#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define TESTCARD "great_hall"

int checkGreatHall(int p, struct gameState * post){
	struct gameState before;
	int newCard = 1;
	int disCard = 0;
	int handCountB = post->handCount[p];
	int numOfTreasureB = 0; /*Number of treasure before playing card*/
	int numOfTreasureA = 0; /*Number of treasure after playing card*/
	memcpy(&before, post, sizeof(struct gameState));
	cardEffect(great_hall,0,0,0,post,0,0);
	int cardDrawn = 0;
	int handCountA = post->handCount[p];
	
	assert(post->handCount[p] == before.handCount[p]);

	assert(post->numBuys == before.numBuys);

	/*coin should be the same*/
	assert(post->coins == before.coins);
	
	assert(post->numActions == before.numActions+1);

	return 0;
}

int main(){
	int i, p, deckCount, discardCount, handCount;
	int numPlayers = 2;
	int numTests;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
	remodel, smithy, village, baron, great_hall};
	
    struct gameState G;
	
	memset(&G,0,sizeof(struct gameState));

    printf ("Testing great_hall.\n");

    printf ("RANDOM TESTS.\n");
	
	SelectStream(2);
    PutSeed(100000000);
	
	for(numTests=0; numTests<2000; numTests++){
		initializeGame(numPlayers,k,numTests, &G);
		p = floor(Random() * 2);
		int ranNum1 = (int) (floor(Random() * MAX_HAND));
		int ranNum2 = (int) (floor(Random() * MAX_MAX_DECK));
		int ranNum3 = (int) (floor(Random() * MAX_MAX_DECK));
		G.handCount[p] = ranNum1;
	    G.deckCount[p] = ranNum2;
        G.discardCount[p] = ranNum3;
        game.whoseTurn = p;
		int lower = estate;
		int higher = treasure_map;
		
		for(i=0; i<G.deckCount[p]; i++){
			G.hand[p][i]=floor((Random() *26)+1);
		}
		checkAdventurer(p, &G);
	}
	printf ("ALL TESTS OK\n");
	
}