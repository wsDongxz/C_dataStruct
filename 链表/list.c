#include "list.h"


list init_list()
{
	listInfo_t* pListInfo = malloc(sizeof(listInfo_t));
	if (NULL == pListInfo)
		return NULL;

	pListInfo->listHeader.pNextNode = NULL;
	pListInfo->listSize = 0;
	return pListInfo;
}

void insertVal_list(list userlist, unsigned int pos, void* data) 
{
	// ������Ч�Լ��
	if (userlist == NULL)
		return;
	if (data == NULL)
		return;

	listInfo_t* pListInfo = (listInfo_t*)userlist;
	if (pos < 0 || pos > pListInfo->listSize) 
	{
		pos = pListInfo->listSize;
	}

	//��������
	listNode_t* pListNode = (listNode_t*)data;
	listNode_t* pCurr = &(pListInfo->listHeader);

	for (int i = 0; i < pos; i++)
	{
		pCurr = pCurr->pNextNode;
	}
	pListNode->pNextNode = pCurr->pNextNode;
	pCurr->pNextNode = pListNode;
	pListInfo->listSize++;
}

void forEach_list(list userList, void(*userPrint)(void*)) 
{

	if (userList == NULL)
		return;
	if (userPrint == NULL)
		return;
	// ��ȡ��Ϣ
	listInfo_t* pListInfo = (listInfo_t*)userList;
	//��Ч����
	listNode_t* pCur = pListInfo->listHeader.pNextNode;
	for (int i = 0; i < pListInfo->listSize; i++)
	{
		userPrint(pCur);
		pCur = pCur->pNextNode;
	}
}

void removeByVal_list(list userList, void* data, int (*compare)(void*, void*)) 
{
	// ������Ч��
	if (userList == NULL)
		return;
	if (data == NULL)
		return;
	if (compare == NULL)
		return;

	listInfo_t* pListInfo = (listInfo_t*)userList;

	if (pListInfo->listSize <= 0)
		return;


	// ��ȡ������Ϣ����һ����Ч����
	listNode_t* pListNode = pListInfo->listHeader.pNextNode;
	listNode_t* pPreNode = &(pListInfo->listHeader);

	// ��������
	for (int i = 0; i < pListInfo->listSize; i++)
	{
		// ɾ���û�ָ��������
		if (1U == compare(data, pListNode)) 
		{
			//����ָ��
			pPreNode->pNextNode = pListNode->pNextNode;
			//���´�С���˳�ѭ��
			pListInfo->listSize--;
			break;
		}
		pPreNode = pListNode;
		pListNode = pListNode->pNextNode;
		
	}
}