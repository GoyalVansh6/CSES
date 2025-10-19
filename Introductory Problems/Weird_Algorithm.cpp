#include <bits/stdc++.h>

int main() {
  long long n;
  std::cin >> n;
  std::cout << n << " ";
  while (n != 1) {
    if (n & 1) {
      n = n * 3 + 1;
      std::cout << n << " ";
    } else {
      n /= 2;
      std::cout << n << " ";
    }
  }
  return 0;
}