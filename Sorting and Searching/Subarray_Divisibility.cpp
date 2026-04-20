#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for(int& i : v){
        cin >> i;
    }

    unordered_map<long long, int> prefixSum;
    prefixSum[0] = 1;

    long long curr_sum = 0;
    long long count = 0;

    for(int i = 0; i < n; i++){
        curr_sum += v[i];
        int rem = curr_sum % n;
        if(rem < 0){
            rem += n;
        }
        count += prefixSum[rem];
        prefixSum[rem]++;
    }

    cout << count << endl;
}