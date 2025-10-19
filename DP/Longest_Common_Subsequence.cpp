#include <bits/stdc++.h>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n, 0);

  for (auto &i : a) {
    std::cin >> i;
  }

  std::vector<int> b(m, 0);

  for (auto &i : b) {
    std::cin >> i;
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = std::max({dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]),
                           dp[i][j - 1], dp[i - 1][j]});
    }
  }

  std::vector<int> lcs;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      lcs.push_back(a[i - 1]);
      i--, j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  std::reverse(lcs.begin(), lcs.end());

  std::cout << dp[n][m] << std::endl;
  for (int i : lcs) {
    std::cout << i << " ";
  }
}

/*
8 6
3 1 3 2 7 4 8 2
6 5 1 2 3 4

3
1 2 4
*/