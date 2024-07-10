#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;            //데이터를 담을 공간
	struct _node* next;  // 연결의 도구!
} Node;

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//데이터를 입력 받는 과정///////
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//노드의 추가과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)           //첫 번째 노드라면
			head = newNode;         //첫 번째 노드를 head가 가리키게 함
		else                        //두 번째 이후의 노드라면
			tail->next = newNode;   //추가된 노드는 연결 리스트의 끝(tail이 가리키는 노드)의 뒤에 연결

		tail = newNode;             //노드의 끝을 tail이 가리키게 함
	}
	printf("\n");

	//입력 받은 데이터의 출력과정 ///////
	printf("입력 받은 데이터의 전체 출력! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;                //cur이 리스트의 첫 번째 노드를 가리킨다
		printf("%d ", cur->data);  //첫 번째 데이터 출력

		while (cur->next != NULL)  //cur이 연결 리스트의 끝이 아니라면 -> 반복
		{
			cur = cur->next;       //cur이 다음 노드를 가리키게 한다
			printf("%d ", cur->data); //cur이 가리키는 노드들 출력한다
		}
	}
	printf("\n\n");

	// 메모리의 해제 과정 ///////
	if (head == NULL)
	{
		return 0;  // 해제할 노드가 존재하지 않는다.
	}
	else
	{
		                                   //head가 가리키는 노드의 삭제를 위해 두 개의 포인터 변수 추가로 선언
		Node* delNode = head;              //삭제될 노드를 가리킴
		Node* delNextNode = head->next;    //삭제될 노드의 다음 노드를 가리킴

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);  //첫 번째 노드 삭제

		while (delNextNode != NULL)  //두 번째 이후 노드 삭제를 위한 반복문
		{
			delNode = delNextNode;                  //delNode 한 칸 이동(원래 delNode가 가리키던 대상은 삭제됨)
			delNextNode = delNextNode->next;        //delNextNode 한 칸 이동

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}
