#include <bits/stdc++.h>
using namespace std;

long long dp[20][2][2];

long long fxn(string s, int pos, bool tight, bool leadingZero){
    if(pos == s.size()) return 1;
    if(dp[pos][tight][leadingZero] != -1) return dp[pos][tight][leadingZero];

    long long ans = 0;
    int ub = tight ? s[pos] - '0' : 9;
    for(int digit = 0; digit <= ub; digit++){
        ans += fxn(s, pos + 1, tight && (digit == ub), leadingZero && (digit == 0));
    }

    return dp[pos][tight][leadingZero] = ans;
}

int main(){
    int a, b;
    cin >> a >> b;

    cout << fxn(to_string(b), 0, true, true) - fxn(to_string(a - 1), 0, true, true) << endl;

    return 0;
}