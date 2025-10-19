#include <bits/stdc++.h>
#define MOD 1000000007

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<char>> grid(n, std::vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> grid[i][j];
    }
  }

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
  dp[1][1] = grid[0][0] != '*' ? 1 : 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1)
        continue;
      if (grid[i - 1][j - 1] == '*')
        continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
  }

  std::cout << dp[n][n];
}