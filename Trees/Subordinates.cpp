#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<vector<int>>& adj, vector<int>& ans){
    ans[u] = 1;
    for(int v : adj[u]){
        ans[u] += dfs(v, adj, ans);
    }
    return ans[u];
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++){
        int u;
        cin >> u;
        adj[u - 1].push_back(i);
    }

    vector<int> ans(n, 0);

    dfs(0, adj, ans);

    for(int i = 0; i < n; i++){
        cout << ans[i] - 1 << " ";
    }
    cout << endl;
}