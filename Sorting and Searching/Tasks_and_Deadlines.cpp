#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> tasks;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        tasks.push_back({a, b});
    }

    sort(tasks.begin(), tasks.end());

    long long ans = 0;
    long long curr = 0;
    
    for(int i = 0; i < n; i++){
        ans += tasks[i].second;
        ans -= curr + tasks[i].first;
        curr += tasks[i].first;
    }

    cout << ans << endl;
}