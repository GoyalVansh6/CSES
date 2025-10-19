#include <bits/stdc++.h>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> v(n, 0);
  std::vector<long long> prefix(n, 0);
  std::cin >> v[0];
  prefix[0] = v[0];
  for (int i = 1; i < n; i++) {
    std::cin >> v[i];
    prefix[i] = v[i] + prefix[i - 1];
  }

  while (q--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << prefix[b - 1] - prefix[a - 1] + v[a - 1] << std::endl;
  }
}