#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
    int n, k;
    cin >> n >> k;

    indexed_set s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }

    int idx = 0;
    while(!s.empty()){
        idx = (idx + k) % s.size();
        cout << *s.find_by_order(idx) << " ";
        s.erase(s.find_by_order(idx));
    }
}