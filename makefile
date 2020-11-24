all: proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h LinkedNodeClass.h
	g++ -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h LinkedNodeClass.h
	g++ -c LIFOStackClass.cpp -o LIFOStackClass.o

project4.o: project4.cpp SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -c project4.cpp -o project4.o

proj4.exe: LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o \ 
           LIFOStackClass.o project4.o
	g++ LinkedNodeClass.o SortedListClass.o project4.o \
      FIFOQueueClass.o LIFOStackClass.o -o proj4.exe

clean:
	rm -rf LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o \ 
     LIFOStackClass.o project4.o proj4.exe