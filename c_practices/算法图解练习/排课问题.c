#include<stdio.h>
#include<string.h>

#define MAX_NUM_LEN 20

typedef struct
{
	char name[MAX_NUM_LEN+1];
	float begin;
	float end;
}Course;

void assignCourse(Course *pa,Course b);

int main(void)
{
	Course room[5];
	Course c[5] = {{"art",9.0,10.0},{"english",9.5,10.0},{"math",10.0,11.0},{"computer",10.5,11.5},{"music",11,12}};
	int course_num = 0;
	
	assignCourse(&room[0],c[0]);
	course_num++;
	
	for(int i=2;i<=5;i++)
	{
		if(c[i-1].begin >= room[course_num-1].end)
		{
			assignCourse(&room[course_num],c[i-1]);
			course_num++;
		}
	}
	
	for(int i=1;i<=course_num;i++)
	{
		printf("name:%s\tbegin:%.2f\tend:%.2f\n",room[i-1].name,room[i-1].begin,room[i-1].end);
	}
	
	return 0;
}

void assignCourse(Course *pa,Course b)
{
	strcpy(pa->name,b.name);
	pa->begin = b.begin;
	pa->end = b.end;
}