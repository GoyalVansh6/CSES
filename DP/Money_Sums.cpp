#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> coins(n);

  for (int &c : coins)
    cin >> c;

  set<int> s;
  for (int coin : coins) {
    vector<int> current(s.begin(), s.end());
    s.insert(coin);
    for (int val : current) {
      s.insert(val + coin);
    }
  }

  cout << s.size() << endl;
  for (int x : s)
    cout << x << " ";
  cout << endl;
}
