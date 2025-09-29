#include <bits/stdc++.h>

std::string BFSSol(std::vector<std::vector<char>> &v,
                   std::vector<std::vector<bool>> &visited,
                   std::pair<int, int> start) {
  
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<char>> v(n, std::vector<char>(m));
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
  std::pair<int, int> start;
  std::pair<int, int> end;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> v[i][j];
      if (v[i][j] == 'A') {
        start.first = i;
        start.second = j;
      }
      if (v[i][j] == 'B') {
        end.first = i;
        end.second = j;
      }
    }
  }

  std::string Ans = BFSSol(v, visited, start);
  if (Ans == "") {
    std::cout << "NO";
    return 0;
  }

  std::cout << "YES" << std::endl << Ans.size() << std::endl << Ans;

  return 0;
}