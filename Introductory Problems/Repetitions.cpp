#include <algorithm>
#include <bits/stdc++.h>

int main() {
  std::string s = "";
  std::cin >> s;
  int n = s.size();
  int Ans = 0;

  for (int i = 0; i < n; i++) {
    int temp = 1;
    while (i < n - 1 && s[i] == s[i + 1])
      temp++, i++;
    Ans = std::max(Ans, temp);
  }

  std::cout << Ans;
}