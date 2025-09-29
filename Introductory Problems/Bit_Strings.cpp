#include<bits/stdc++.h>
#define MOD 1000000007

long long fxn(long long a, int n){
    if(n == 0) return 1;
    if(n & 1){
        return (a * fxn(a, n - 1)) % MOD;
    }
    else{
        return fxn((a * a) % MOD, n / 2) % MOD;
    }
}

int main(){
    int n;
    std::cin >> n;
    std::cout << fxn(2, n);
}