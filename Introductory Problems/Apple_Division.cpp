#include<bits/stdc++.h>

long long fxn(std::vector<int> &v, int index, long long sum, long long currSum){
    if(index >= v.size() || currSum >= sum/2){
        return currSum;
    }

    long long included = fxn(v, index + 1, sum, currSum + v[index]);
    included = included >= sum/2 ? included : INT64_MAX;
    long long excluded = fxn(v, index + 1, sum, currSum);
    excluded = excluded >= sum/2 ? excluded : INT64_MAX;

    return std::min(included, excluded);
}

int main(){
    int n;
    std::cin >> n;

    long long sum = 0;
    std::vector<int> v(n, 0);
    for(int &i : v){
        std::cin >> i;
        sum += i;
    }

    long long temp = fxn(v, 0, sum, 0);
    std::cout << std::abs(2*temp - sum);
}

/*

5
3 2 7 4 1, sum = 17
sum/2 = 8

*/