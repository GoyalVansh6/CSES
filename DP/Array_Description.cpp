#include <bits/stdc++.h>
#define MOD 1000000007

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> values(n);
  for (auto &i : values)
    std::cin >> i;

  std::vector<int> prev(m + 2, 0), curr(m + 2, 0);

  if (values[0] == 0) {
    for (int j = 1; j <= m; j++)
      prev[j] = 1;
  } else {
    prev[values[0]] = 1;
  }

  for (int i = 1; i < n; i++) {
    memset(curr.data(), 0, (m + 2) * sizeof(int));
    if (values[i] == 0) {
      for (int j = 1; j <= m; j++) {
        curr[j] = ((long long)prev[j - 1] + prev[j] + prev[j + 1]) % MOD;
      }
    } else {
      int v = values[i];
      curr[v] = ((long long)prev[v - 1] + prev[v] + prev[v + 1]) % MOD;
    }
    prev = curr;
  }

  long long Ans = 0;
  if (values[n - 1] == 0) {
    for (int j = 1; j <= m; j++)
      Ans = (Ans + prev[j]) % MOD;
  } else {
    Ans = prev[values[n - 1]];
  }

  std::cout << Ans;
}
