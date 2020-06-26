all : demo clean

Object = demo.o BitTree.o Stack.o Queue.o

demo : $(Object)
	gcc -o demo $(Object)
	
demo.o : demo.c BitTree.h
	gcc -c demo.c
	
BitTree.o : BitTree.c BitTree.h
	gcc -c BitTree.c

Stack.o : Stack.c Stack.h
	gcc -c Stack.c
		
Queue.o : Queue.c Queue.h
	gcc -c Queue.c
	
.PHONY : clean

clean : 
	del $(Object)