#include <bits/stdc++.h>

int main() {
  int n;
  long long sum = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }

  for (int i = 0; i < n - 1; i++) {
    int temp;
    std::cin >> temp;
    sum -= temp;
  }
  std::cout << sum;
}