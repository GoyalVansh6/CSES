#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    long long temp = 5;
    int Ans = 0;
    while(temp <= n){
        Ans += n / temp;
        temp *= 5;
    } 
    std::cout << Ans;
}