#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    int prev = 0;
    long long Ans = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        std::cin >> temp;
        if(temp > prev){
            prev = temp;
            continue;
        }
        else{
            Ans += prev - temp;
        }
    }
    std::cout << Ans;
}