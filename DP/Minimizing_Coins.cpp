#include <bits/stdc++.h>

int main() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> coins(n);

  for (int &i : coins) {
    std::cin >> i;
  }

  std::vector<int> dp(x + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (int coin : coins) {
      if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
        dp[i] = std::min(dp[i], dp[i - coin] + 1);
      }
    }
  }

  std::cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}