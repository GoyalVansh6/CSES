#include <bits/stdc++.h>
#define MOD 1000000007

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n + 1, 0);
  a[0] = 1;

  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      if (i + j <= n) {
        a[i + j] += a[i] % MOD;
      }
    }
  }

  std::cout << a[n] % MOD;
}