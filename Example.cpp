#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	Node* next;
}node; // 구조체 이름 바꾸기 가능, Node




int main() {
	Node* head = (Node*)malloc(sizeof(Node)); //동적할당, *head외우기
	head->data = 10;

	Node*tail= (Node*)malloc(sizeof(Node)); //동적할당, *head외우기
	tail->data = 20;

	head->next = tail; // head를 tail과 연결

	printf("%d, %d", head->data,head->next->data); // head에 있는 연결을 통해 data 값을 가져옴

	free(head); //c언어는 다른 언어와 다르게 메모리 해제까지 해줘야 누수가 안생김
	free(tail);

	return 0;
}