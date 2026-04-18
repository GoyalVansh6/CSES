#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;

    vector<int> p(n, 0);
    for(int& i : p){
        cin >> i;
    }

    set<int> positions;
    multiset<int> gaps;

    positions.insert(0);
    positions.insert(x);
    gaps.insert(x);

    for(int i : p){
        auto it = positions.upper_bound(i);
        
        int right = *it;
        int left = *(--it);
        
        positions.insert(i);
        gaps.erase(gaps.find(right - left));
        gaps.insert(i - left);
        gaps.insert(right - i);

        cout << *gaps.rbegin() << " ";
    }
}