#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

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

    std::cout << Ans;
}

/*

5
4 2 1 5 3

*/