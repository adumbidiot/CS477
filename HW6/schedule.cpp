#include <climits>
#include <iostream>
#include <stdint.h>

void print_c(int *c, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = c[(i * n) + j];
      std::cout << x << " ";
      if (x < 10)
        std::cout << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  int x[] = {10, 1, 7, 7};
  int s[] = {8, 4, 2, 1};
  int n = 4;

  int c[n + 1][n + 1];

  for (int i = 0; i < n + 1; i++)
    c[i][0] = 0;

  for (int i = 1; i < n + 1; i++) {

    int max_index = 0;
    for (int k = 0; k < n; k++) {
      if (c[k][i - 1] > c[max_index][i - 1]) {
        max_index = k;
      }
    }

    c[0][i] = c[max_index][i - 1];

    for (int j = 1; j < n + 1; j++) {
      c[j][i] = c[j - 1][i - 1] + std::min(s[j - 1], x[i - 1]);
    }
  }

  int max_index = 0;
  for (int i = 0; i < n + 1; i++)
    if (c[max_index][n] < c[i][n])
      max_index = i;

  std::cout << "C Table: \n";
  print_c(c[0], n + 1);
  std::cout << "\n";

  std::cout << "Max Data Processed: " << c[max_index][n] << std::endl;

  return 0;
}