#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  int n;
  vector<long long> tree;
  const long long INF = LLONG_MAX / 4;

  void buildUtil(const vector<int> &v, int node, int l, int r) {
    if (l == r) {
      tree[node] = v[l];
      return;
    }
    int mid = l + (r - l) / 2;
    buildUtil(v, 2 * node + 1, l, mid);
    buildUtil(v, 2 * node + 2, mid + 1, r);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
  }

  long long queryUtil(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return INF;
    if (ql <= l && r <= qr)
      return tree[node];
    int mid = l + (r - l) / 2;
    long long left = queryUtil(2 * node + 1, l, mid, ql, qr);
    long long right = queryUtil(2 * node + 2, mid + 1, r, ql, qr);
    return min(left, right);
  }

  void updateUtil(int node, int l, int r, int idx, int val) {
    if (l == r) {
      tree[node] = val;
      return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid)
      updateUtil(2 * node + 1, l, mid, idx, val);
    else
      updateUtil(2 * node + 2, mid + 1, r, idx, val);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
  }

public:
  SegmentTree(int size = 0) {
    n = size;
    tree.assign(4 * max(1, n), LLONG_MAX / 4);
  }

  void build(const vector<int> &v) {
    if (v.empty())
      return;
    n = (int)v.size();
    tree.assign(4 * n, LLONG_MAX / 4);
    buildUtil(v, 0, 0, n - 1);
  }

  long long rangeMin(int a, int b) {
    if (a > b)
      return LLONG_MAX / 4;
    return queryUtil(0, 0, n - 1, a, b);
  }

  void update(int idx, int val) { updateUtil(0, 0, n - 1, idx, val); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  if (!(cin >> n >> q))
    return 0;
  vector<int> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  SegmentTree T;
  T.build(v);

  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      T.update(a - 1, b);
    } else {
      // range min query on [a, b] 1-based
      cout << T.rangeMin(a - 1, b - 1) << '\n';
    }
  }
  return 0;
}
