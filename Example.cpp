#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	Node* next;
}node; // ����ü �̸� �ٲٱ� ����, Node




int main() {
	Node* head = (Node*)malloc(sizeof(Node)); //�����Ҵ�, *head�ܿ��
	head->data = 10;

	Node*tail= (Node*)malloc(sizeof(Node)); //�����Ҵ�, *head�ܿ��
	tail->data = 20;

	head->next = tail; // head�� tail�� ����

	printf("%d, %d", head->data,head->next->data); // head�� �ִ� ������ ���� data ���� ������

	free(head); //c���� �ٸ� ���� �ٸ��� �޸� �������� ����� ������ �Ȼ���
	free(tail);

	return 0;
}