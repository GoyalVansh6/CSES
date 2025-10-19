#include <bits/stdc++.h>

int main() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> price(n, 0), pages(n, 0);

  for (int &i : price) {
    std::cin >> i;
  }

  for (int &i : pages) {
    std::cin >> i;
  }

  std::vector<int> prev(x + 1, 0);
  std::vector<int> curr(x + 1, 0);

  int maxPages = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= x; j++) {
      if (j - price[i] >= 0)
        curr[j] = std::max(prev[j - price[i]] + pages[i], prev[j]);
      maxPages = std::max(maxPages, curr[j]);
    }
    prev = curr;
  }

  std::cout << maxPages;
}