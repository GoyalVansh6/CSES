#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  vector<int> tree;
  int n;

  void buildUtil(vector<int> &v, int node, int start, int end) {
    if (start == end) {
      tree[node] = v[start];
      return;
    }
    int mid = start + (end - start) / 2;
    buildUtil(v, 2 * node + 1, start, mid);
    buildUtil(v, 2 * node + 2, mid + 1, end);
    tree[node] = tree[2 * node + 1] ^ tree[2 * node + 2];
  }

  int queryUtil(int node, int start, int end, int a, int b) {
    if (a > end || b < start) {
      return 0;
    }
    if (a <= start && end <= b) {
      return tree[node];
    }
    int mid = start + (end - start) / 2;
    int left = queryUtil(2 * node + 1, start, mid, a, b);
    int right = queryUtil(2 * node + 2, mid + 1, end, a, b);
    return left ^ right;
  }

public:
  SegmentTree(int size) {
    tree.assign(4 * size, 0);
    n = size;
  }

  void build(vector<int> &v) { buildUtil(v, 0, 0, n - 1); }

  int query(int a, int b) { return queryUtil(0, 0, n - 1, a, b); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  SegmentTree T(n);
  T.build(v);

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << T.query(a - 1, b - 1) << "\n";
  }

  return 0;
}
