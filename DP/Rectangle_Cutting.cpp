#include <bits/stdc++.h>

int main() {
  int n, m;
  std::cin >> n >> m;
  int count = 0;

  std::vector<std::vector<int>> dp(n, std::vector<int>(m, INT32_MAX));

  for (int i = 0; i < n; i++) {
    dp[i][0] = i;
  }

  for (int i = 0; i < m; i++) {
    dp[0][i] = i;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (i == j) {
        dp[i][j] = 0;
      } else {
        for (int k = 0; k < i; k++) {
          dp[i][j] = std::min(dp[k][j] + dp[i - k - 1][j] + 1, dp[i][j]);
        }
        for (int k = 0; k < j; k++) {
          dp[i][j] = std::min(dp[i][k] + dp[i][j - k - 1] + 1, dp[i][j]);
        }
      }
    }
  }

  std::cout << dp[n - 1][m - 1];
}

/*

dp metric, i, j min slices upto i and j
 _ _ _ _ _ _ _ _
|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|
|_|_|_|_|_|_|_|_|

 _ _
|_|_|
|_|_|

 _ _ _
|_|_|_|
|_|_|_|
|_|_|_|

 _ _ _ _
|_|_|_|_|
|_|_|_|_|
|_|_|_|_|
|_|_|_|_|
*/