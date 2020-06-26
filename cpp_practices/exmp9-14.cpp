//类模板

#include<iostream>

using namespace std;

template <typename numtype>

class Compare
{
	public:
		Compare(numtype a,numtype b)
		{
			x = a;
			y = b;
		}
		
		numtype max(void);
		
		numtype min(void);
		
	private:
		numtype x;
		numtype y;
};

int main(void)
{
	Compare <int> cmpint(3,7);
	
	cout << "cmpint.max =" << cmpint.max() << endl;
	cout << "cmpint.min =" << cmpint.min() << endl;
	
	return 0;
}

template <typename numtype>
numtype Compare<numtype>::max(void)
{
	return x>y? x:y;
}

template <typename numtype>
numtype Compare<numtype>::min(void)
{
	return x>y? y:x;
}