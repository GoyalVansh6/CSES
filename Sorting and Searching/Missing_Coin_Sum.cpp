#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> values(n, 0);

    for(int& i : values){
        std::cin >> i;
    }

    std::sort(values.begin(), values.end());

    long long temp = 1;
    for(int i : values){
        if(i > temp){
            std::cout << temp;
            return 0;
        }
        temp += i;
    }

    std::cout << temp;
}