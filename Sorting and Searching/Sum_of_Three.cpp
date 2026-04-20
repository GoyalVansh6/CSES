#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int target = x - v[i].first;
        int low = i + 1;
        int high = n - 1;

        while(low < high){
            if(v[low].first + v[high].first == target){
                cout << v[i].second << " " << v[low].second << " " << v[high].second << endl;
                return 0;
            }
            else if(v[low].first + v[high].first < target){
                low++;
            }
            else{
                high--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}