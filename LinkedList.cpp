#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	int data;
	Node* next;

}Node;


// 기초적인 4개의 함수

Node* CreateHead(int data); 
void CreateNode(Node* head, int data);
void PrintNodes(Node* head);
void DestroyList(Node* head);

int main() {
	Node* head = CreateHead(1);
	CreateNode(head, 2);
	CreateNode(head, 3);
	CreateNode(head, 4);
	PrintNodes(head);
	DestroyList(head);

	//printf("%d", head->data); //head에 있는 data값 해제완료~! 오류떠야 정상

	return 0;
}

//머리 만들어주기
Node* CreateHead(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL; //올지 안올지 모른다
	return temp;
}

//리스트의 마지막에 올노드들 만들고 연결해주는 함수
void CreateNode(Node* head, int data)
{
	while (true)						//노드의 다음의 존재가 하지 않으면 자리 만들어 주기
	{
		if (head->next == NULL)
			break;
		head = head->next;
	}

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;

	head->next = temp; // 꼬리까지 달아주기

}


//노드 출력 함수
void PrintNodes(Node* head)
{
	while (head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
}

//빈자리 자리 치워주기(빈자리 = 노드)
void DestroyList(Node* head)
{
	if (head->next)      // 같은 문장 if(head->next != NULL)
		DestroyList(head->next);

	free(head);
}

