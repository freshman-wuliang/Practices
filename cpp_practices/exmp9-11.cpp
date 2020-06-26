#include<iostream>
#include<string>

using namespace std;

class Student
{
	public :
		Student(string n,int a,float s);   //构造函数
		
		Student(const Student &s);   //复制构造函数
		
		~Student();   //析构函数
		
		void displayInfo(void);
		
		static int stuTotal(void);
		
		static float aveScore(void);
		
		static float sum;   //所有学生的成绩总和
		
		static int count;   //所有学生的人数
		
	private :
		string num;
		int age;
		float score;
};

float Student::sum;
int Student::count;

int main(void)
{
	Student stu[3] = {
		Student("001",18,70.1),
		Student("002",19,78.2),
		Student("003",20,98.3)
	};
	
	//cout << "stu num:" << Student::count << endl;
	//cout << "stu sum:" << Student::sum << endl;
	for(int i=1;i<=3;i++)
	{
		stu[i-1].displayInfo();
	}
	
	cout << "average:" << Student::aveScore() << endl;
	
	return 0;
}

Student::Student(string n,int a,float s)
{
	num = n;
	age = a;
	score = s;
	count++;
	sum += score;
}

Student::Student(const Student &s)
{
	num = s.num;
	age = s.age;
	score = s.score;
	count++;
	sum += s.score;
}

Student::~Student()
{
	count--;
	sum -= this->score;
	cout << "destructor call" << endl;
}

void Student::displayInfo(void)
{
	cout << "num:" << num << endl;
	cout << "age:" << age << endl;
	cout << "score:" << score << endl;
}

int Student::stuTotal(void)
{
	return count;
}

float Student::aveScore(void)
{	
	return sum / count;
}