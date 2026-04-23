#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<char>> v(n, vector<char>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    unordered_map<char, map<pair<int, int>, int>> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int x = j + 1; x < n; x++){
                if(v[i][j] == v[i][x]){
                    m[v[i][j]][{j, x}]++;
                }
            }
        }
    }

    for(int i = 0; i < k; i++){
        bool flag = false;
        for(auto& [first, second]: m[i + 'A']){
            if(second >= 2){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}