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

  for (int i = 0; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i + coins[j] <= x) {
        dp[i + coins[j]] += dp[i] % MOD;
        dp[i + coins[j]] %= MOD;
      } else {
        break;
      }
    }
  }

  std::cout << dp[x];
}