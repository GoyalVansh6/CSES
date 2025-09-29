#include <bits/stdc++.h>

class SegmentTree {
  int n;
  std::vector<long long> tree;

  void buildUtil(std::vector<int> &v, int node, int start, int end) {
    if (start == end) {
      tree[node] = v[start];
      return;
    }

    int mid = start + (end - start) / 2;
    buildUtil(v, 2 * node + 1, start, mid);
    buildUtil(v, 2 * node + 2, mid + 1, end);
    tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
  }

  long long AnsUtil(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
      return INT32_MAX;

    if (l <= start && end <= r)
      return tree[node];

    int mid = start + (end - start) / 2;
    long long left = AnsUtil(2 * node + 1, start, mid, l, r);
    long long right = AnsUtil(2 * node + 2, mid + 1, end, l, r);
    return std::min(left, right);
  }

public:
  SegmentTree(int size) {
    n = size;
    tree.assign(4 * n, 0);
  }

  void build(std::vector<int> &v) { buildUtil(v, 0, 0, v.size() - 1); }

  long long min(int a, int b) { return AnsUtil(0, 0, n - 1, a, b); }
};

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> v(n, 0);

  for (int &i : v)
    std::cin >> i;

  SegmentTree T(n);
  T.build(v);
  while (q--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << T.min(a - 1, b - 1) << std::endl;
  }
}