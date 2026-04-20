#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> v(n, 0);
    for(int& i : v){
        cin >> i;
    }

    unordered_map<long long, int> prefixSum;
    prefixSum[0] = 1;

    long long curr_sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        curr_sum += v[i];
        count += prefixSum[curr_sum - x];
        prefixSum[curr_sum]++;
    }

    cout << count << endl;
}