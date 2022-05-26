#include "darray.h"

dArrInfo* init_DynamicArray(int capacity)
{
	// 数据有效性判断
	if (capacity <= 0)
		return NULL;

	// 数据管理信息初始化
	dArrInfo* pArrayInfo = (dArrInfo*)malloc(sizeof(dArrInfo));
	
	if (NULL == pArrayInfo)
		return NULL;
	pArrayInfo->m_Capacity = capacity;
	pArrayInfo->m_Size = 0;
	pArrayInfo->pArray = malloc(sizeof(void*) * capacity);

	return pArrayInfo;
}

/******************************************************
* Brief: insert Data
* Parameter:
*		pArrayInfo	:	ArrayInfo
*		pos			:	数据插入位置
*		pData		：	数据地址
* Return: 
*			1:	数据插入成功
*			0：	数据插入失败
*******************************************************/

int insert_DynamicArray(dArrInfo* pArrayInfo, int pos, void* pData)
{
	// 1. 数据有效性验证
	if (NULL == pArrayInfo)
		return 0;
	if (NULL == pData)
		return 0;
	if (pos > pArrayInfo->m_Size || pos < 0)
		pos = pArrayInfo->m_Size;
	// 2. 空间是否足够
	if (pArrayInfo->m_Size >= pArrayInfo->m_Capacity) 
	{
		// 01 计算新空间大小，申请新空间
		int newCapacity = sizeof(void*) * pArrayInfo->m_Capacity * 2;
		void** pNewArray = malloc(newCapacity);
		if (NULL == pNewArray)
			return 0;
		// 02 将原数据拷贝至新空间
		memcpy(pNewArray, pArrayInfo->pArray, pArrayInfo->m_Capacity * sizeof(void*));
		// 03 释放原空间
		free(pArrayInfo->pArray);
		// 04 更新指针指向
		pArrayInfo->pArray == pNewArray;
		// 05 更新容量
		pArrayInfo->m_Capacity = newCapacity;
		return 1;
	}
	// 3. 后移法 -- 数据插入
	for (int i = pArrayInfo->m_Size - 1; i > pos; i--) 
	{
		pArrayInfo->pArray[i] = pArrayInfo->pArray[i - 1];
	}
	pArrayInfo->pArray[pos] = pData;

	// 4. 更新大小
	pArrayInfo->m_Size++;

}

void forEach_DynamicArray(dArrInfo* pArrayInfo, void(*pFunc)(void*)) 
{
	if (NULL == pArrayInfo)
		return;
	if (NULL == pFunc)
		return;
	for (int i = 0; i < pArrayInfo->m_Size; i++) 
	{
		pFunc(pArrayInfo->pArray[i]);
	}
}

int deletByIndex_DynamicArray(dArrInfo* pArrayInfo, int index) 
{
	// 1. 数据有效性检查
	if (NULL == pArrayInfo)
		return 0;
	if (index < 0 || index >= pArrayInfo->m_Size)
		return 0;
	// 2. 数据删除, 后面的数据前移，最后的数据设置为NULL
	for (int i = index; i < pArrayInfo->m_Size - 1; i++) 
	{
		pArrayInfo->pArray[i] = pArrayInfo->pArray[i + 1];
	}
	// 3. 更新Size
	pArrayInfo->m_Size--;
	return 1;
}

int deletByVal_DynamicArray(dArrInfo* pArrayInfo, void* pData, int (*userCompare)(void*, void*))
{
	// 1. 数据有效性检查
	if (NULL == pArrayInfo)
		return 0;
	if (NULL == pData)
		return 0;
	if (NULL == userCompare)
		return 0;
	// 2. 数据删除, 后面的数据前移，最后的数据设置为NULL
	for (int i = 0; i < pArrayInfo->m_Size; i++) 
	{
		if (1U == userCompare(pData, pArrayInfo->pArray[i])) 
		{
			// 删除元素
			for (int j = i; j < pArrayInfo->m_Size - 1; j++) 
			{
				pArrayInfo->pArray[j] = pArrayInfo->pArray[j + 1];
			}
			// 3. 更新Size
			pArrayInfo->m_Size -= 1;
			break;
		}
	}
}

void destroy_DynamicArray(dArrInfo* pArrayInfo)
{
	// 1. 数据有效性验证
	if (NULL == pArrayInfo)
		return;
	// 2. 释放堆区空间
	if (NULL != pArrayInfo->pArray) 
	{
		free(pArrayInfo->pArray);
		pArrayInfo->pArray = NULL;
		pArrayInfo->m_Size = 0;
		pArrayInfo->m_Capacity = 0;
	}
	free(pArrayInfo);
	pArrayInfo = NULL;
}
