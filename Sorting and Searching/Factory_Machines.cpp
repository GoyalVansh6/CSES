#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> k(n, 0);
    for(int& i : k){
        cin >> i;
    }

    long long low = 1;
    long long high = 1e18;
    long long ans = 1e18;

    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long count = 0;
        for(int i = 0; i < n; i++){
            count += mid / k[i];
            if (count >= t) break;
        }
        if(count >= t){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}