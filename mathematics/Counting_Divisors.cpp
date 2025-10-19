#include <bits/stdc++.h>

int main() {
    std::vector<int> v(1000001, 0);
    for(int i = 1; i < 1000001; i++){
        for(int j = i; j < 1000001; j += i){
            v[j]++;
        }
    }
    
    int n;
    std::cin >> n;
    
    while(n--){
        int x;
        std::cin >> x;
        std::cout << v[x] << std::endl;
    }

    return 0;
}
