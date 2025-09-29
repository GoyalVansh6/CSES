#include <bits/stdc++.h>

void handleRoom(std::vector<std::vector<char>> &v,
                std::vector<std::vector<bool>> &visited, int i, int j) {
  std::queue<std::pair<int, int>> q;
  q.push({i, j});
  visited[i][j] = true;
  while (!q.empty()) {
    std::pair<int, int> p = q.front();
    int a = p.first;
    int b = p.second;
    q.pop();
    if (a > 0 && v[a - 1][b] == '.' && !visited[a - 1][b]) {
      q.push({a - 1, b});
      visited[a - 1][b] = true;
    }
    if (a < v.size() - 1 && v[a + 1][b] == '.' && !visited[a + 1][b]) {
      q.push({a + 1, b});
      visited[a + 1][b] = true;
    }
    if (b < v[0].size() - 1 && v[a][b + 1] == '.' && !visited[a][b + 1]) {
      q.push({a, b + 1});
      visited[a][b + 1] = true;
    }
    if (0 < b && v[a][b - 1] == '.' && !visited[a][b - 1]) {
      q.push({a, b - 1});
      visited[a][b - 1] = true;
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> v(n, std::vector<char>(m));
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

  for (auto &row : v) {
    for (auto &cell : row) {
      std::cin >> cell;
    }
  }

  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.' && !visited[i][j]) {
        count++;
        handleRoom(v, visited, i, j);
      } else {
        visited[i][j] = true;
        continue;
      }
    }
  }

  std::cout << count;
}