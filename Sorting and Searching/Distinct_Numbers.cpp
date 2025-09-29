#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n, 0);
  int Ans = 1;

  for (int &i : v) {
    std::cin >> i;
  }

  std::sort(v.begin(), v.end());

  for (int i = 1; i < n; i++) {
    if (v[i] != v[i - 1])
      Ans++;
  }

  std::cout << Ans;
}