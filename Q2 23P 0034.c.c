#include <stdio.h>

int collatz_length(int n) {
  int count = 1;
  while (n != 1) {
    n = (n % 2 == 0 ? n / 2 : 3 * n + 1);
    count += 1;
  }
  return count;
}

int longest_collatz_sequence(int n) {
  int max_length = 0;
  int number = 0;
  for (int i = 1; i <= n; i += 1) {
    int length = collatz_length(i);
    if (length > max_length) {
      max_length = length;
      number = i;
    }
  }
}

int main() {
  int input;
  printf("Input a number: ");
  scanf("%d", &input);
  printf("Longest Sequence: %d\n", longest_collatz_sequence(input));
  return 0;
}