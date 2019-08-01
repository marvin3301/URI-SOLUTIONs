#include <cstdio>

int main() {

  int fact[9];
  fact[0] = 1;
  for (int i = 1; i <= 8; i++) fact[i] = i*fact[i-1];

  int N;
  scanf("%d", &N);

  int x = 0;
  for (int i = 8; i >= 0; i--) {
    x += (N/fact[i]);
    N = N%fact[i];
  }

  printf("%d\n", x);

  return 0;
}
