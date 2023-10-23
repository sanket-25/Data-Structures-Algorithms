#include <stdio.h>

void linearSearch(int n, int arr[], int k) {
  //Linear Search
  int flag = 0;
  for (int i = 0; i < n; i++) {

    if (k == arr[i]) {
      printf("Index is : %d\n", i);
      flag = 1;
      break;
    }

  }
  if (flag == 0) {
    printf("Please enter an element from the list of array above\n");
  }
}

void binarySearch(int n, int arr[], int k) {
  //Binary Search
  int start = 0;
  int end = n - 1;
  int found = 0;
  
  while (start<=end) {
    int mid = (start + end) / 2;
    if (k == arr[mid]) {
      printf("Index is : %d\n", mid);
      found = 1;
      break;
    } else if (k < arr[mid]) {
      end = mid - 1;
    } else if (k > arr[mid]) {
      start = mid + 1;
    }
  }
  
  if(found==0){
      printf("Please enter an element from the list of array above\n");
  }
}

int main() {
  int n = 10;
  int arr[10] = {
    1,
    3,
    4,
    6,
    23,
    43,
    454,
    555,
    557,
    810
  };

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  while(1){
  printf("\nEnter the element to be found : ");
  int k;
  scanf("%d", &k);

  printf("1-> Linear, 2-> Binary\nWhich searching algorithm : ");
  int whichAlgorithm;
  scanf("%d", &whichAlgorithm);
  switch (whichAlgorithm) {
  case 1:
    linearSearch(n, arr, k);
    break;
  case 2:
    binarySearch(n, arr, k);
    break;
  default:
    printf("Enter valid input");
    break;
  }
  }
  return 0;
}