#include<bits/stdc++.h>

int GCDVector(std::vector<int> &count){
    int Ans = 0;
    for(int i = 1; i < 1000001; i++){
        int multiples = 0;
        for(int j = i; j < 1000001; j += i){
            multiples += count[j];
            if(multiples > 1){
                Ans = std::max(Ans, i);
                continue;
            }
        }
    }
    return Ans;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<int> v(n, 0);
    std::vector<int> count(1000001, 0);
    for(int &i : v){
        std::cin >> i;
        count[i]++;
    }

    std::cout << GCDVector(count) << std::endl;
    return 0;
}