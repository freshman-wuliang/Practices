all : BitTree clean

BitTree : main.o BitTree.o
	gcc -o BitTree main.o BitTree.o
	
main.o : main.c BitTree.h
	gcc -c main.c

BitTree.o : BitTree.c BitTree.h
	gcc -c BitTree.c

.PHONY : clean

clean :
	del *.o