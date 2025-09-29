#include<bits/stdc++.h>
#define MOD 1000000007

int pow(long long a, int n){
    if(n == 0) return 1;

    if(n & 1){
        return (a * pow(a, n - 1)) % MOD;
    }
    else{
        return pow((a * a) % MOD, n / 2) % MOD;
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << pow(a, pow(b, c)) << std::endl;
    }
}