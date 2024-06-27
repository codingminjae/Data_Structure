#include <stdio.h>

int BSearch(int arr[], int size, int target) {
  int first, last, mid;
  first = 0;
  last = size - 1;
  while (first <= last) {
    mid = (first + last) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      last = mid;
    } else {
      first = mid;
    }
  }
  return -1;
}

int main(void) {
  int arr[] = {1, 3, 5, 7, 9};
  int idx;
  idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
  if (idx == -1) {
    printf("탐색실패\n");
  } else {
    printf("타겟 저장 인덱스: %d \n", idx);
  }

  idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
  if (idx == -1) {
    printf("탐색실패");
  } else {
    printf("타겟 저장 인덱스: %d \n", idx);
  }
  return 0;
}
