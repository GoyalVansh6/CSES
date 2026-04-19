#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n, 0);
    for(int& i : v){
        cin >> i;
    }

    sort(v.begin(), v.end());

    long long sum_except_last = 0;
    for(int i = 0; i < n - 1; i++){
        sum_except_last += v[i];
    }

    if(sum_except_last > v[n - 1]){
        cout << sum_except_last + v[n - 1] << endl;
    }
    else{
        cout << 2 * v[n - 1] << endl;
    }
}