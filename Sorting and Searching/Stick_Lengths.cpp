#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> lengths(n, 0);

    for(int& i : lengths){
        std::cin >> i;
    }

    std::sort(lengths.begin(), lengths.end());

    long long Ans = 0;
    for(int i : lengths){
        Ans += std::abs(i - lengths[n/2]);
    }

    std::cout << Ans;
}