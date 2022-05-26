#ifndef __DARRAY_H__
#define __DARRAY_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dAyy {
	void** pArray;
	unsigned int m_Capacity;
	unsigned int m_Size;
} dArrInfo;


dArrInfo* init_DynamicArray(int capacity);
int insert_DynamicArray(dArrInfo* pArrayInfo, int pos, void* pData);
void forEach_DynamicArray(dArrInfo* pArrayInfo, void(*pFunc)(void*));
int deletByIndex_DynamicArray(dArrInfo* pArrayInfo, int index);
int deletByVal_DynamicArray(dArrInfo* pArrayInfo, void* pData, int (*userCompare)(void*, void*));
void destroy_DynamicArray(dArrInfo* pArrayInfo);

#endif // !__DARRAY_H__
