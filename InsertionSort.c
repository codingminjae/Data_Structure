#include <stdio.h>

#define SIZE 100

void InsertSort(int arr[], int n) {
	int i, j;
	int insData;

	for (int i = 1; i < n; i++) {
		insData = arr[i];  //정렬 대상을 insData에 저장

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j]; //비교대상을 한 칸 뒤로 밀기
			else
				break; //삽입 위치를 찾았으니 탈출
		}

		arr[j + 1] = insData; //찾은 위치에 정렬대상 삽입!
	}
}

int main() {
	int arr[SIZE];
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	InsertSort(arr, num);

	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
