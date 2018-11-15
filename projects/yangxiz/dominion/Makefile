CFLAGS= -Wall -fpic -fprofile-arcs -ftest-coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out

randomtestcard1.out:
	gcc -o randomtest1 randomtest1.c -g dominion.c rngs.c -g $(CFLAGS)
	echo "randomtest1" >> randomtestresults.out
	./randomtest1 >> randomtestresults.out
	randomtest1 >> randomtestresults.out
	gcov randomtest1.c >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
randomtestcard2.out:
	gcc -o randomtest2 randomtest2.c -g dominion.c rngs.c -g $(CFLAGS)
	echo "randomtest2" >> randomtestresults.out
	./randomtest2 >> randomtestresults.out
	randomtest2 >> randomtestresults.out
	gcov randomtest2.c >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
randomtestadventurer.out:
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.c -g $(CFLAGS)
	echo "randomtestadventurer" >> randomtestresults.out
	./randomtestadventurer >> randomtestresults.out
	randomtestadventurer >> randomtestresults.out
	gcov randomtestadventurer.c >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testcard1.exe