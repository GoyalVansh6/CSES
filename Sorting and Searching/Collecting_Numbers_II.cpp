#include<bits/stdc++.h>

int main(){
    int n, count;
    std::cin >> n >> count;

    std::vector<int> values(n, 0);

    for(int& i : values){
        std::cin >> i;
    }

    std::unordered_map<int,bool> m;
    int Ans = 1;

    for(int i : values){
        if(m[i+1] == true){
            Ans++;
        }
        m[i] = true;
    }

    int a, b;
    while(count--){
        std::cin >> a >> b;
        if(values[b-1] > values[a-1]) Ans++;
        else Ans--;
        std::swap(values[a-1], values[b-1]);
        std::cout << Ans << std::endl;
    }
}