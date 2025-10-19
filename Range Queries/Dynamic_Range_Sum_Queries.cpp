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
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
  }

  long long AnsUtil(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
      return 0;

    if (l <= start && end <= r)
      return tree[node];

    int mid = start + (end - start) / 2;
    long long left = AnsUtil(2 * node + 1, start, mid, l, r);
    long long right = AnsUtil(2 * node + 2, mid + 1, end, l, r);
    return left + right;
  }

  void updateUtil(std::vector<int> &v, int node, int start, int end, int k,
                  int u) {
    if (k > end || k < start)
      return;

    if (start == end) {
      tree[node] += u - v[k];
      return;
    }

    if (k >= start && k <= end) {
      tree[node] += u - v[k];
      int mid = start + (end - start) / 2;
      updateUtil(v, 2 * node + 1, start, mid, k, u);
      updateUtil(v, 2 * node + 2, mid + 1, end, k, u);
    }
  }

public:
  SegmentTree(int size) {
    n = size;
    tree.assign(4 * n, 0);
  }

  void build(std::vector<int> &v) { buildUtil(v, 0, 0, v.size() - 1); }

  long long sum(int a, int b) { return AnsUtil(0, 0, n - 1, a, b); }

  void update(std::vector<int> &v, int k, int u) {
    updateUtil(v, 0, 0, n - 1, k, u);
    v[k] = u;
  }
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
    int k;
    std::cin >> k;
    if (k == 1) {
      int a, b;
      std::cin >> a >> b;
      T.update(v, a - 1, b);
    } else {
      int a, b;
      std::cin >> a >> b;
      std::cout << T.sum(a - 1, b - 1) << std::endl;
    }
  }
}