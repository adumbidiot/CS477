// Build: g++ problem2.cpp -o problem2
// Fmt: clang-format -i *.cpp
#include <algorithm>
#include <cstdio>

void partition(int *arr, size_t low, size_t high) {
  size_t mid = 0;
  for (int i = 0; i <= high; i++) {
    if (arr[i] < 0) {
      std::swap(arr[mid], arr[i]);
      mid += 1;
    }
  }
}

void dump_int_array(int *arr, size_t len) {
  for (size_t i = 0; i < len; i++)
    printf("%d ", arr[i]);
}

int main() {
  int data[] = {4, 3, -2, 0, 2, 9, -1, 10, 0, 5, 23, -4};
  size_t data_len = 12;

  printf("Not Partitioned:\n");
  dump_int_array(data, data_len);
  printf("\n");

  partition(data, 0, data_len - 1);

  printf("Partitioned:\n");
  dump_int_array(data, data_len);
  printf("\n");

  return 0;
}