#include <bits/stdc++.h>

void fxn(int a, int b) {
  if (a < b) {
    fxn(b, a);
    return;
  }

  int temp = a - b;
  a -= temp * 2;
  b -= temp;

  std::cout << (a >= 0 && b >= 0 && a % 3 == 0 && b % 3 == 0 ? "YES" : "NO")
            << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    fxn(a, b);
  }
}