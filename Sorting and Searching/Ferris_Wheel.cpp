#include<bits/stdc++.h>

int main(){
    int n, x;
    std::cin >> n >> x;
    std::vector<int> weights(n, 0);

    for(int& i : weights){
        std::cin >> i;
    }

    std::sort(weights.begin(), weights.end());

    int left = 0, right = n-1;
    int Ans = 0;
    while(left < right){
        if(weights[left] + weights[right] <= x){
            Ans++;
            left++;
            right--;
        }
        else{
            Ans++;
            right--;
        }
    }

    if(left == right) Ans++;

    std::cout << Ans;
}