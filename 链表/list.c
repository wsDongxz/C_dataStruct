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
	// 数据有效性检查
	if (userlist == NULL)
		return;
	if (data == NULL)
		return;

	listInfo_t* pListInfo = (listInfo_t*)userlist;
	if (pos < 0 || pos > pListInfo->listSize) 
	{
		pos = pListInfo->listSize;
	}

	//插入数据
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
	// 获取信息
	listInfo_t* pListInfo = (listInfo_t*)userList;
	//有效数据
	listNode_t* pCur = pListInfo->listHeader.pNextNode;
	for (int i = 0; i < pListInfo->listSize; i++)
	{
		userPrint(pCur);
		pCur = pCur->pNextNode;
	}
}

void removeByVal_list(list userList, void* data, int (*compare)(void*, void*)) 
{
	// 数据有效性
	if (userList == NULL)
		return;
	if (data == NULL)
		return;
	if (compare == NULL)
		return;

	listInfo_t* pListInfo = (listInfo_t*)userList;

	if (pListInfo->listSize <= 0)
		return;


	// 获取链表信息，第一个有效数据
	listNode_t* pListNode = pListInfo->listHeader.pNextNode;
	listNode_t* pPreNode = &(pListInfo->listHeader);

	// 遍历链表
	for (int i = 0; i < pListInfo->listSize; i++)
	{
		// 删除用户指定的数据
		if (1U == compare(data, pListNode)) 
		{
			//更新指针
			pPreNode->pNextNode = pListNode->pNextNode;
			//更新大小并退出循环
			pListInfo->listSize--;
			break;
		}
		pPreNode = pListNode;
		pListNode = pListNode->pNextNode;
		
	}
}