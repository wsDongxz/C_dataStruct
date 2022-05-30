#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*********************数据类型定义*************************/
typedef void* list;
typedef void* listNode;

typedef struct listNode {
	void* pNextNode;
}listNode_t;

typedef struct listInfo {
	listNode_t listHeader;
	unsigned int listSize;
} listInfo_t;


list init_list();
void insertVal_list(list userlist, unsigned int pos, void* data);
void forEach_list(list userList, void(*userPrint)(void*));
void removeByVal_list(list userList, void* data, int (*compare)(void*, void*));






#endif // !__LIST_H__

