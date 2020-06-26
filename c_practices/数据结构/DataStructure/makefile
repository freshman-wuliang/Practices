all : ceshi clean

ceshi : ceshi.o datastr.o
	gcc -o ceshi ceshi.o datastr.o
	
ceshi.o : ceshi.c datastr.h
	gcc -c ceshi.c
datastr.o : datastr.c datastr.h
	gcc -c datastr.c
	
.PHONY : clean

clean :
	del *.o