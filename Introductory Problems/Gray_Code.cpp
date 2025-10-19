#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  int temp = 1;
  for (int i = 0; i < n; i++) {
    temp = temp << 1;
  }

  for (int i = 0; i < temp; i++) {
    std::bitset<16> bs = i ^ (i >> 1);
    std::string gray = bs.to_string().substr(16 - n);
    std::cout << gray << std::endl;
  }
  return 0;
}