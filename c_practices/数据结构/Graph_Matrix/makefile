all : demo clean

Object = main.o Graph.o Stack.o Queue.o

demo : $(Object)
	gcc -o demo $(Object)
	
main.o : main.c Graph.h
	gcc -c main.c
	
Graph.o : Graph.c Graph.h
	gcc -c Graph.c

Stack.o : Stack.c Stack.h
	gcc -c Stack.c
		
Queue.o : Queue.c Queue.h
	gcc -c Queue.c
	
.PHONY : clean

clean : 
	del $(Object)