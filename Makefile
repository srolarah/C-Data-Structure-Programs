#Makefile
#Sarah Rolfe
#str9wed

CXX=clang++

a.out: huffmandec.o huffListnode.o
	$(CXX) huffmandec.o huffListnode.o

huffmandec.o: huffmandec.cpp

huffListnode.o: huffListnode.cpp huffListnode.h

.PHONY: clean
clean:
	-rm -f *.o a.out
