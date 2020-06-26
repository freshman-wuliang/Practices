all : main clean

Object = main.o Point.o Circle.o Cylinder.o

main : $(Object)
	g++ -o main $(Object)
	
Point.o : Point.cpp Point.h
	g++ -c Point.cpp

Circle.o : Circle.cpp Circle.h
	g++ -c Circle.cpp
	
Cylinder.o : Cylinder.cpp Cylinder.h
	g++ -c Cylinder.cpp
	
.PHONY : clean

clean : 
	del *.o