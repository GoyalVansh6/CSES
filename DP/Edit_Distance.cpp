#include <bits/stdc++.h>

int main() {
  std::string a = "";
  std::string b = "";

  std::cin >> a >> b;

  int n = a.size();
  int m = b.size();

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

  for (int i = 0; i <= n; i++)
    dp[i][0] = i;
  for (int i = 0; i <= m; i++)
    dp[0][i] = i;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = std::min({dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
                           dp[i - 1][j] + 1, dp[i][j - 1] + 1});
    }
  }

  std::cout << dp[n][m];
}