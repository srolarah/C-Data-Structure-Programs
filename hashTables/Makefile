#Makefile
#Sarah Rolfe
#str9wed

CXX=clang++

a.out: timer.o wordPuzzle.o hashTable.o
	$(CXX) timer.o wordPuzzle.o hashTable.o

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out

