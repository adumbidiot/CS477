// Build: g++ problem2.cpp -o problem2
// Fmt: clang-format -i *.cpp
#include <cstdio>
#include <limits.h>

void minmax(int *arr, size_t start, size_t end, int &min, int &max) {
  if (start == end) {
    if (arr[start] > max)
      max = arr[start];
    if (arr[start] < min)
      min = arr[start];
  } else if (end - start == 1) {
    if (arr[start] < arr[end]) {
      if (arr[end] > max)
        max = arr[end];
      if (arr[start] < min)
        min = arr[start];
    } else {
      if (arr[start] > max)
        max = arr[start];
      if (arr[end] < min)
        min = arr[end];
    }
  } else {
    size_t mid = (end + start) / 2;
    minmax(arr, start, mid, min, max);
    minmax(arr, mid + 1, end, min, max);
  }
}

int main() {
  int data[] = {1, 4, 9, 3, 4, 9, 5, 6, 9, 3, 7};
  size_t data_len = 11;

  int min = INT_MAX;
  int max = INT_MIN;
  minmax(data, 0, data_len - 1, min, max);

  printf("Min: %i\nMax: %i", min, max);

  return 0;
}