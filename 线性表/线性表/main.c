#include <stdio.h>
#include "darray.h"

typedef struct stu {
	char name[20];
	unsigned int age;
	char address[30];
} T_Stu;

void stuPrint(void* pData);
int compareStu(void* pData1, void* pData2);


int main() 
{
	
	dArrInfo* pStuArrInfo = init_DynamicArray(30);
	T_Stu stu1 = { "ɳĮ����", 500, "ˡ����" };
	T_Stu stu2 = { "��ľľ", 3000, "��������½" };
	T_Stu stu3 = { "����֮��", 27, "��ŷ����" };
	T_Stu stu4 = { "����֮��", 40, "�ȶ�������" };
	T_Stu stu5 = { "��������", 30, "��������" };
	T_Stu stu6 = { "������˹", 30, "ŵ����˹" };
	insert_DynamicArray(pStuArrInfo, 0, &stu1);
	insert_DynamicArray(pStuArrInfo, 1, &stu2);
	insert_DynamicArray(pStuArrInfo, 2, &stu3);
	insert_DynamicArray(pStuArrInfo, 3, &stu4);
	insert_DynamicArray(pStuArrInfo, 4, &stu5);
	insert_DynamicArray(pStuArrInfo, 5, &stu6);
	forEach_DynamicArray(pStuArrInfo, stuPrint);


	deletByIndex_DynamicArray(pStuArrInfo, 2);
	deletByVal_DynamicArray(pStuArrInfo, &stu4, compareStu);
	forEach_DynamicArray(pStuArrInfo, stuPrint);
	destroy_DynamicArray(pStuArrInfo);

	return 0;
}

void stuPrint(void* pData) 
{
	T_Stu* pStu = (T_Stu*)pData;
	printf("*************************************\n");
	printf("name: %s\n", pStu->name);
	printf("age: %d\n", pStu->age);
	printf("address: %s\n", pStu->address);
}

int compareStu(void* pData1, void* pData2) 
{
	if (NULL == pData1 || NULL == pData2)
		return 0;
	T_Stu* pStu1 = (T_Stu*)pData1;
	T_Stu* pStu2 = (T_Stu*)pData2;
	if ((0U == strcmp(pStu1->address, pStu2->address)) && pStu1->age == pStu2->age &&
		(0U == strcmp(pStu1->name, pStu2->name)))
		return 1;
	else
		return 0;
}