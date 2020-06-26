all : demo clean

Object = main.o Network.o

demo : $(Object)
	gcc -o demo $(Object)
	
main.o : main.c Network.h
	gcc -c main.c
	
Network.o : Network.c Network.h
	gcc -c Network.c
	
.PHONY : clean

clean : 
	del $(Object)