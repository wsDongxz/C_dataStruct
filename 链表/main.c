#include <stdio.h>
#include "list.h"

typedef struct student 
{
	listNode nextNode;
	char name[20];
	unsigned int age;

}stu_t;

void printStu(void* stu);
void test01();
int compareStu(void* stu1, void* stu2);


int main() 
{
	test01();
	return 0;
}


void test01() 
{
	stu_t stu1 = { NULL, "AAA", 10 };
	stu_t stu2 = { NULL, "BBB", 20 };
	stu_t stu3 = { NULL, "CCC", 30 };
	stu_t stu4 = { NULL, "DDD", 40 };
	stu_t stu5 = { NULL, "EEE", 50 };
	list stuList = init_list();
	insertVal_list(stuList, 0, &stu1);
	insertVal_list(stuList, 0, &stu2);
	insertVal_list(stuList, 0, &stu3);
	insertVal_list(stuList, 10, &stu4);
	insertVal_list(stuList, 2, &stu5);
	forEach_list(stuList, printStu);
	printf("------------------------\n");
	removeByVal_list(stuList, &stu2, compareStu);
	removeByVal_list(stuList, &stu1, compareStu);
	forEach_list(stuList, printStu);
	
}

void printStu(void* stu) 
{
	stu_t* l_stu = (stu_t*)stu;
	printf("%s\t%d\n", l_stu->name, l_stu->age);
}

int compareStu(void* stu1, void* stu2) 
{
	stu_t* pStu1 = (stu_t*)stu1;
	stu_t* pStu2 = (stu_t*)stu2;
	return (strcmp(pStu1->name, pStu2->name)==0 && pStu1->age == pStu2->age);
}