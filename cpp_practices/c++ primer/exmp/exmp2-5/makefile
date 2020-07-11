all : exmp clean

objects = exmp2-5.o Sales_data.o

exmp : $(objects)
	g++ -Wall -o exmp $(objects)

exmp2-5.o : exmp2-5.cpp Sales_data.h
	g++ -Wall -c exmp2-5.cpp

Sales_data.o : Sales_data.cpp Sales_data.h
	g++ -Wall -c Sales_data.cpp

.PHONY : clean

clean :
	rm *.o