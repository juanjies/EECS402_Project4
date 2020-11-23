all: proj4.exe

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h
	g++ -c SortedListClass.cpp -o SortedListClass.o

project4.o: project4.cpp SortedListClass.h
	g++ -c project4.cpp -o project4.o

proj4.exe: LinkedNodeClass.o SortedListClass.o project4.o
	g++ LinkedNodeClass.o SortedListClass.o project4.o -o proj4.exe

clean:
	rm -rf LinkedNodeClass.o SortedListClass.o project4.o proj4.exe