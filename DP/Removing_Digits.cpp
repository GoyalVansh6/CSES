#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, INT32_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int temp = i;
    while (temp) {
      int rem = temp % 10;
      temp /= 10;
      if (rem == 0)
        continue;
      dp[i] = std::min(dp[i], dp[i - rem] + 1);
    }
  }

  std::cout << dp[n];
}