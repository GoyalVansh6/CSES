#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  vector<long long> tree;
  int n;

  void updateUtil(int node, int start, int end, int a, int b, int u) {
    if (a > end || b < start)
      return;

    if (a <= start && end <= b) {
      tree[node] += u;
      return;
    }

    int mid = (start + end) / 2;
    updateUtil(2 * node + 1, start, mid, a, b, u);
    updateUtil(2 * node + 2, mid + 1, end, a, b, u);
  }

  long long queryUtil(int node, int start, int end, int idx) {
    if (idx < start || idx > end)
      return 0;
    if (start == end)
      return tree[node];

    int mid = (start + end) / 2;
    return tree[node] + queryUtil(2 * node + 1, start, mid, idx) + queryUtil(2 * node + 2, mid + 1, end, idx);
  }

public:
  SegmentTree(int size) {
    n = size;
    tree.assign(4 * size, 0);
  }

  void update(int a, int b, int u) { updateUtil(0, 0, n - 1, a, b, u); }
  long long query(int k) { return queryUtil(0, 0, n - 1, k); }
};

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> v(n);
  for (long long &i : v)
    cin >> i;

  SegmentTree T(n);

  while (q--) {
    int mode;
    cin >> mode;

    if (mode == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      T.update(a - 1, b - 1, u);
    } else {
      int k;
      cin >> k;
      cout << v[k - 1] + T.query(k - 1) << "\n";
    }
  }
}
