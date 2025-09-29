#include <bits/stdc++.h>
#define MOD 1000000007

int main() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> coins(n, 0);

  for (int &i : coins) {
    std::cin >> i;
  }

  std::sort(coins.begin(), coins.end());
  std::vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= x; j++) {
      if ((j - coins[i]) >= 0) {
        dp[j] += dp[j - coins[i]] % MOD;
        dp[j] %= MOD;
      }
    }
  }
  std::cout << dp[x];
}