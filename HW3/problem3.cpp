// Build: g++ problem3.cpp -o problem3
// Fmt: clang-format -i *.cpp
#include <algorithm>
#include <cstdio>

void merge(int *arr, int *temp, size_t start, size_t mid, size_t end) {
  size_t i = start;
  size_t j = mid + 1;
  size_t k = start;

  while (i <= mid && j <= end) {
    if (arr[i] < arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }

  while (i <= mid)
    temp[k++] = arr[i++];

  while (j <= end)
    temp[k++] = arr[j++];

  for (size_t i = start; i <= end; i++)
    arr[i] = temp[i];
}

void mergesort(int *arr, int *temp, size_t start, size_t end) {
  for (size_t i = 1; i <= end - start; i *= 2) {
    for (size_t j = start; j < end; j += 2 * i) {
      size_t start_inner = j;
      size_t mid = j + i - 1;
      size_t end_inner = std::min(j + 2 * i - 1, end);

      merge(arr, temp, start_inner, mid, end_inner);
    }
  }
}

void dump_int_array(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++)
    printf("%d ", arr[i]);
}

int main() {
  const size_t ARR_LEN = 12;
  int arr[ARR_LEN] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7, 2};
  int temp[ARR_LEN] = {0};

  printf("Original: ");
  dump_int_array(arr, ARR_LEN);
  printf("\n");

  mergesort(arr, temp, 0, ARR_LEN - 1);

  printf("Sorted:   ");
  dump_int_array(arr, ARR_LEN);
  printf("\n");

  return 0;
}