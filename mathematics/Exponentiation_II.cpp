#include<bits/stdc++.h>

long long pow(long long a, int n, long long MOD){
    if(n == 0) return 1;

    if(n & 1){
        return (long long)(a * pow(a, n - 1, MOD)) % MOD;
    }
    else{
        return (long long)pow((a * a) % MOD, n / 2, MOD) % MOD;
    }
}

int main(){
    int t;
    std::cin >> t;
    while(t--){
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << pow(a, pow(b, c, 1000000006), 1000000007) << std::endl;
    }
    return 0;
}

/*
since MOD is prime
according to fermet little equation / Eulers theorem :
    a ^ φ(n) ≡ 1(modn)
    φ(n) = coprimes to n uptil n - 1
    for prime n its n - 1

1000000007 -> 1000000006
a ^ 1000000006 - 1 % MOD = 0
*/