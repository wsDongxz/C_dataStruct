#include "darray.h"

dArrInfo* init_DynamicArray(int capacity)
{
	// ������Ч���ж�
	if (capacity <= 0)
		return NULL;

	// ���ݹ�����Ϣ��ʼ��
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
*		pos			:	���ݲ���λ��
*		pData		��	���ݵ�ַ
* Return: 
*			1:	���ݲ���ɹ�
*			0��	���ݲ���ʧ��
*******************************************************/

int insert_DynamicArray(dArrInfo* pArrayInfo, int pos, void* pData)
{
	// 1. ������Ч����֤
	if (NULL == pArrayInfo)
		return 0;
	if (NULL == pData)
		return 0;
	if (pos > pArrayInfo->m_Size || pos < 0)
		pos = pArrayInfo->m_Size;
	// 2. �ռ��Ƿ��㹻
	if (pArrayInfo->m_Size >= pArrayInfo->m_Capacity) 
	{
		// 01 �����¿ռ��С�������¿ռ�
		int newCapacity = sizeof(void*) * pArrayInfo->m_Capacity * 2;
		void** pNewArray = malloc(newCapacity);
		if (NULL == pNewArray)
			return 0;
		// 02 ��ԭ���ݿ������¿ռ�
		memcpy(pNewArray, pArrayInfo->pArray, pArrayInfo->m_Capacity * sizeof(void*));
		// 03 �ͷ�ԭ�ռ�
		free(pArrayInfo->pArray);
		// 04 ����ָ��ָ��
		pArrayInfo->pArray == pNewArray;
		// 05 ��������
		pArrayInfo->m_Capacity = newCapacity;
		return 1;
	}
	// 3. ���Ʒ� -- ���ݲ���
	for (int i = pArrayInfo->m_Size - 1; i > pos; i--) 
	{
		pArrayInfo->pArray[i] = pArrayInfo->pArray[i - 1];
	}
	pArrayInfo->pArray[pos] = pData;

	// 4. ���´�С
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
	// 1. ������Ч�Լ��
	if (NULL == pArrayInfo)
		return 0;
	if (index < 0 || index >= pArrayInfo->m_Size)
		return 0;
	// 2. ����ɾ��, ���������ǰ�ƣ�������������ΪNULL
	for (int i = index; i < pArrayInfo->m_Size - 1; i++) 
	{
		pArrayInfo->pArray[i] = pArrayInfo->pArray[i + 1];
	}
	// 3. ����Size
	pArrayInfo->m_Size--;
	return 1;
}

int deletByVal_DynamicArray(dArrInfo* pArrayInfo, void* pData, int (*userCompare)(void*, void*))
{
	// 1. ������Ч�Լ��
	if (NULL == pArrayInfo)
		return 0;
	if (NULL == pData)
		return 0;
	if (NULL == userCompare)
		return 0;
	// 2. ����ɾ��, ���������ǰ�ƣ�������������ΪNULL
	for (int i = 0; i < pArrayInfo->m_Size; i++) 
	{
		if (1U == userCompare(pData, pArrayInfo->pArray[i])) 
		{
			// ɾ��Ԫ��
			for (int j = i; j < pArrayInfo->m_Size - 1; j++) 
			{
				pArrayInfo->pArray[j] = pArrayInfo->pArray[j + 1];
			}
			// 3. ����Size
			pArrayInfo->m_Size -= 1;
			break;
		}
	}
}

void destroy_DynamicArray(dArrInfo* pArrayInfo)
{
	// 1. ������Ч����֤
	if (NULL == pArrayInfo)
		return;
	// 2. �ͷŶ����ռ�
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
