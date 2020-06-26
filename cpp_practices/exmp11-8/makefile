all : main clean

Object = main.o Student.o Teacher.o Graduate.o

main : $(Object)
	g++ -o main $(Object)
	
Student.o : Student.cpp Student.h
	g++ -c Student.cpp

Teacher.o : Teacher.cpp Teacher.h
	g++ -c Teacher.cpp
	
Graduate.o : Graduate.cpp Graduate.h
	g++ -c Graduate.cpp
	
.PHONY : clean

clean : 
	del *.o