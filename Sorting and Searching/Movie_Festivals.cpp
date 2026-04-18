#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);

    for(int i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    });

    int ans = 0;
    int lastEnd = 0;

    for(auto movie : movies){
        if(movie.first >= lastEnd){
            ans++;
            lastEnd = movie.second;
        }
    }

    cout << ans << endl;
}