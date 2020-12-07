CC=gcc
CFLAGS=-I.

main: main.o nodeWord.o nodeSentence.o linkedList.o driver.o 
	$(CC)  main.o nodeWord.o nodeSentence.o linkedList.o driver.o

nodeWord.o: nodeWord.c
	$(CC) -c nodeWord.c

nodeSentence.o: nodeSentence.c nodeWord.h
	$(CC) -c nodeSentence.c

linkedList.o: linkedList.c nodeSentence.h
	$(CC) -c linkedList.c

driver.o: driver.c linkedList.h
	$(CC) -c driver.c

main.o: main.c driver.h
	$(CC) -c main.c

clean:
	rm -f nodeWord.o nodeSentence.o linkedList.o driver.o main.o

