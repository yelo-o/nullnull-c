#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

USERDATA* g_pHeadNode = NULL; // 가리키는 도구

void AddNewNode(int age, const char* pszName, const char* pszPhone)
{
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	if (g_pHeadNode == NULL) // 아무곳도 안 가리키면
		g_pHeadNode = pNewNode;
	else // 새 노드 추가하기 (tail node에 추가)
	{
		USERDATA* pTail = g_pHeadNode;
		while (pTail->pNext != NULL)
			pTail = pTail->pNext;
		pTail->pNext = pNewNode;
	}
}

void ReleaseList(void)
{
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete = g_pHeadNode;
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete: [%p] %d, %s, %s [%p]\n",
			pDelete, pDelete->age, pDelete->name, pDelete->phone,
			pDelete->pNext);

		free(pDelete);
	}

	g_pHeadNode = NULL; // 연결 리스트가 하나도 없을 때는 NULL 이기 때문에
}

void InitDummyData(void)
{
	//Input
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Choi", "010-2222-2222");
	AddNewNode(13, "Jang", "010-3333-3333");
}

void PrintList(void)
{
	// Print list
	USERDATA* pTmp = g_pHeadNode;
	while (pTmp != NULL)
	{
		printf("[%p] %d, %s, %s [%p]\n",
			pTmp, pTmp->age, pTmp->name, pTmp->phone,
			pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

int main(void)
{
	InitDummyData();
	PrintList();
	ReleaseList();

	return 0;
}
