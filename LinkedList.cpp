#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	int data;
	Node* next;

}Node;


// �������� 4���� �Լ�

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

	//printf("%d", head->data); //head�� �ִ� data�� �����Ϸ�~! �������� ����

	return 0;
}

//�Ӹ� ������ֱ�
Node* CreateHead(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL; //���� �ȿ��� �𸥴�
	return temp;
}

//����Ʈ�� �������� �ó��� ����� �������ִ� �Լ�
void CreateNode(Node* head, int data)
{
	while (true)						//����� ������ ���簡 ���� ������ �ڸ� ����� �ֱ�
	{
		if (head->next == NULL)
			break;
		head = head->next;
	}

	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;

	head->next = temp; // �������� �޾��ֱ�

}


//��� ��� �Լ�
void PrintNodes(Node* head)
{
	while (head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
}

//���ڸ� �ڸ� ġ���ֱ�(���ڸ� = ���)
void DestroyList(Node* head)
{
	if (head->next)      // ���� ���� if(head->next != NULL)
		DestroyList(head->next);

	free(head);
}

