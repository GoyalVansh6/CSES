#include <bits/stdc++.h>

void fxn(std::vector<int> &freq, int n, std::string s) {
  if (n == 0) {
    std::cout << s << std::endl;
    return;
  }

  for (int i = 0; i < 26; i++) {
    if (freq[i]) {
      freq[i]--;
      s.push_back(i + 'a');
      fxn(freq, n - 1, s);
      freq[i]++;
      s.pop_back();
    }
  }
}

int fact(int n) {
  if (n <= 1)
    return 1;
  return n * fact(n - 1);
}

int main() {
  std::string s = "";
  std::cin >> s;
  std::vector<int> freq(26, 0);
  long long count = fact(s.size());
  for (char c : s)
    freq[c - 'a']++;

  for (int i : freq) {
    count /= fact(i);
  }
  std::cout << count << std::endl;
  fxn(freq, s.size(), "");
  return 0;
}