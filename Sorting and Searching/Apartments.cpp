#include <bits/stdc++.h>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n, 0), b(m, 0);

  for (int &i : a) {
    std::cin >> i;
  }

  for (int &i : b) {
    std::cin >> i;
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int Ans = 0;

  int i = 0, j = 0;
  while (i < n && j < m) {
    if (b[j] < a[i] - k) {
      j++;
    } else if (b[j] > a[i] + k) {
      i++;
    } else {
      i++;
      j++;
      Ans++;
    }
  }

  std::cout << Ans;
}