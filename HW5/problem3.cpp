// Build: g++ problem3.cpp -o problem3
// Fmt: clang-format -i *.cpp
#include <algorithm>
#include <cstdio>

void heap_max_heapify(int *heap, size_t heap_size, size_t index);

// Runtime: O(n)
size_t heap_locate_element(int *heap, size_t heap_size, int element) {
  for (size_t i = 0; i < heap_size;
       i++)                 // --- * --- Possibly n iterations, O(n)
    if (heap[i] == element) //     |
      return i;             //     |
  return SIZE_MAX;          // --- *
}

// Runtime: Removal is O(1), heapify is O(log(n)), O(1) + O(log(n)) = O(log(n) +
// 1) = O(log(n))
void heap_remove_element(int *heap, size_t *heap_size, size_t index) {
  *heap_size = *heap_size - 1;    // --- * --- Constant time, O(1)
  heap[index] = heap[*heap_size]; // --- *
  heap_max_heapify(heap, *heap_size, index / 2); // O(log(n))
}

// Runtime: Problem space decreases by 2 at each level, O(log(n))
void heap_max_heapify(int *heap, size_t heap_size, size_t index) {
  size_t largest_index = index;
  size_t left_index = index * 2 + 1;
  size_t right_index = index * 2 + 2;

  if (left_index < heap_size && heap[left_index] > heap[index])
    largest_index = left_index;

  if (right_index < heap_size && heap[right_index] > heap[index])
    largest_index = right_index;

  if (largest_index != index) {
    std::swap(heap[index], heap[largest_index]);
    heap_max_heapify(heap, heap_size, largest_index);
  }
}

void heap_print(int *heap, size_t heap_size) {
  for (size_t i = 0; i < heap_size; i++)
    printf("%d ", heap[i]);
}

// Runtime excluding prints: O(n) + O(log(n)) = O(n)
int main() {
  int heap[] = {9, 6, 8, 2, 5, 7};
  size_t heap_size = 6;
  int value = 6;

  printf("Starting Heap: ");
  heap_print(heap, heap_size);
  printf("\n");

  size_t value_index = heap_locate_element(heap, heap_size, value); // O(log(n))
  printf("Element Index: %i\n", value_index);

  if (value_index < heap_size)
    heap_remove_element(heap, &heap_size, value_index); // O(n)

  printf("Ending Heap: ");
  heap_print(heap, heap_size);
  printf("\n");

  return 0;
}