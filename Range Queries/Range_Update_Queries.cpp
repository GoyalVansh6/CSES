#include <bits/stdc++.h>

class SegmentTree {
  std::vector<int> tree;
  int n;

  void updateUtil(int node, int start, int end, int a, int b, int u) {
    if (a > end || b < start) {
      return;
    }

    if (a <= start && end <= b) {
      tree[node] += u;
      return;
    }

    int mid = start + (end - start) / 2;
    updateUtil(2 * node + 1, start, mid, a, b, u);
    updateUtil(2 * node + 2, mid + 1, end, a, b, u);
  }

  int queryUtil(int node, int start, int end, int idx) {
    if (idx < start || end < idx) {
      return 0;
    }

    return tree[node] +
           queryUtil(2 * node + 1, start, start + (end - start) / 2, idx) +
           queryUtil(2 * node + 2, start + (end - start) / 2 + 1, end, idx);
  }

public:
  SegmentTree(int size) {
    n = size;
    tree.assign(4 * size, 0);
  }

  void update(int a, int b, int u) { updateUtil(0, 0, n - 1, a, b, u); }

  int query(int k) { return queryUtil(0, 0, n - 1, k); }
};

int main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> v(n, 0);

  for (int &i : v) {
    std::cin >> i;
  }

  SegmentTree T(n);

  while (q--) {
    int mode;
    std::cin >> mode;

    if (mode == 1) {
      int a, b, u;
      std::cin >> a >> b >> u;
      T.update(a, b, u);
    } else {
      int k;
      std::cin >> k;
      std::cout << v[k - 1] + T.query(k - 1) << std::endl;
    }
  }
}