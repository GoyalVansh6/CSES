#include<bits/stdc++.h>

// long long Sum_Of_Divisors(int n){
//     long long total = 1;

//     for(int i = 2; i * i <= n; i++){
//         if(n % i == 0){
//             long long temp = 1;
//             while(n % i == 0){
//                 temp *= i;
//                 n /= i;
//             }
//             total *= (temp * i - 1)/(i - 1);
//         }
//     }

//     if(n > 1){
//         total *= (1LL * n * n - 1)/(n - 1);
//     }

//     return total;
// }

int main(){
    int n;
    std::cin >> n;
    std::unordered_map<int,int> done;

    for(int i = 2; i <= n; i++){
        
    }
}