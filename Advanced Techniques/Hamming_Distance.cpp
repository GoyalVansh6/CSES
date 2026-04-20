#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int num = 0;
        for(char& c : s){
            num = (num << 1) | (c - '0');
        }
        v[i] = num;
    }

    int minHammingDistance = k;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int hammingDistance = __builtin_popcount(v[i] ^ v[j]);
            minHammingDistance = min(minHammingDistance, hammingDistance);
        }
    }

    cout << minHammingDistance << endl;
}