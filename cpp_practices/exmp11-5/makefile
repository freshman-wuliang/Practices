all : main clean

main : main.o Student.o Student1.o
	g++ -o main main.o Student.o Student1.o
	
Student.o : Student.cpp Student.h
	g++ -c Student.cpp

Student1.o : Student1.cpp Student1.h
	g++ -c Student1.cpp
	
.PHONY : clean

clean : 
	del *.o