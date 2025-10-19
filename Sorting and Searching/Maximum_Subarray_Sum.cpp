#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> values(n, 0);

    for(int& i : values){
        std::cin >> i;
    }

    long long currSum = values[0];
    long long maxSum = values[0];

    for(int i = 1; i < n; i++){
        currSum = std::max((long long)values[i], currSum + values[i]);
        maxSum = std::max(maxSum, currSum);
    }

    std::cout << maxSum;
}