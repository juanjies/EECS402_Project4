all: proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h LinkedNodeClass.h
	g++ -c FIFOQueueClass.cpp -o FIFOQueueClass.o	

project4.o: project4.cpp SortedListClass.h FIFOQueueClass.h
	g++ -c project4.cpp -o project4.o

proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o project4.o
	g++ LinkedNodeClass.o SortedListClass.o project4.o \
      FIFOQueueClass.o -o proj4.exe

clean:
	rm -rf LinkedNodeClass.o SortedListClass.o project4.o FIFOQueueClass.o \
			proj4.exe