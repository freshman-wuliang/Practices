#include<iostream>

using namespace std;

class Good
{
	public:
		Good(int n=0,int q=0,float p=0.0);
		
		Good(const Good &g);
		
		~Good();
		
		void display(void);
		
		static float showSum(void);
		
		static float average(void);
		
		static float discount;
		static int amount;
		static float sum;
		
	private:
		int num;
		int quantity;
		float price;
};

float Good::discount = 0.98;
int Good::amount;
float Good::sum;

int main(void)
{
	Good goods[3] = {
		Good(101,5,23.5),
		Good(102,12,24.56),
		Good(103,100,21.5)
	};
	
	for(int i=1;i<=3;i++)
	{
		goods[i-1].display();
	}
	cout << "sum:" << Good::showSum() << endl;
	cout << "ave:" << Good::average() << endl;
	
	return 0;
}

Good::Good(int n,int q,float p)
{
	num = n;
	quantity = q;
	price = p;
	
	if(quantity >= 10)
	{
		sum += quantity * price * discount;
	}
	else
	{
		sum += quantity * price;
	}
	amount++;
}

Good::Good(const Good &g)
{
	num = g.num;
	quantity = g.quantity;
	price = g.price;
	
	if(g.quantity >= 10)
	{
		sum += g.quantity * g.price * discount;
	}
	else
	{
		sum += g.quantity * g.price;
	}
	amount++;
	
}

Good::~Good()
{
	if(quantity >= 10)
	{
		sum -= quantity * price * discount;
	}
	else
	{
		sum -= quantity * price;
	}
	amount--;
	
	cout << "class::Good destructor call" << endl;
}

void Good::display(void)
{
	cout << "num:" << num << "," << "quantity:" << quantity << ",";
	cout << "price:" << price << endl;
}

float Good::showSum(void)
{
	return sum;
}

float Good::average(void)
{
	return sum / amount;
}
