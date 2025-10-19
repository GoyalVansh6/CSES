#include <bits/stdc++.h>

int main() {
  std::string input = "";
  std::cin >> input;

  std::vector<int> freq(26, 0);
  int count = 0;

  for (char c : input) {
    freq[c - 'A']++;
    if (freq[c - 'A'] & 1)
      count++;
    else
      count--;
  }

  if (count > 1) {
    std::cout << "NO SOLUTION" << std::endl;
    return 0;
  }

  std::string Ans = "";
  char middle = 'a';
  for (int i = 0; i < 26; i++) {
    if (freq[i] & 1) {
      middle = i + 'A';
      freq[i]--;
    }
    while (!(freq[i] & 1) && freq[i] > 0) {
      Ans += i + 'A';
      freq[i] -= 2;
    }
  }

  int size = Ans.size();
  if (middle != 'a')
    Ans += middle;
  std::string temp = Ans.substr(0, size);
  std::reverse(temp.begin(), temp.end());
  Ans.append(temp);
  std::cout << Ans;
  return 0;
}