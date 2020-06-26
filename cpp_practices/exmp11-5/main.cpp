#include<iostream>
#include"Student.h"
#include"Student1.h"

using namespace std;

int main(void)
{
	Student s("001","wuliang","boy");
	Student1 s1("001","wuliang","boy",23,"hunan");
	
	//s.display();
	//s1.getValue1();
	s1.display1();
	cout << endl;
	
	return 0;
}