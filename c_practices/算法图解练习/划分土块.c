#include<stdio.h>

typedef struct
{
	int length;
	int width;
}SoilBlock;

int devide(SoilBlock s);

int main(void)
{
	SoilBlock s = {168,64};
	
	printf("length:%d\n",devide(s));
	
	return 0;
}

int devide(SoilBlock s)
{
	if(s.length > s.width)
	{
		if(s.length % s.width == 0)
		{
			return s.width;
		}
	}
	else if(s.length < s.width)
	{
		if(s.width % s.length == 0)
		{
			return s.length;
		}
	}
	else
	{
		return s.length;
	}
	
	SoilBlock s1;
	SoilBlock *p = &s1;
	if(s.length > s.width)
	{
		p->length = s.length % s.width;
		p->width = s.width;
	}
	else
	{
		p->width = s.width % s.length;
		p->length = s.length;
	}
	return devide(s1);
}