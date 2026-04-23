#include <bits/stdc++.h>
using namespace std;

void generateSums(int index, int end, long long currentSum, vector<int>& v, vector<long long>& sums){
    if(index == end){
        sums.push_back(currentSum);
        return;
    }
    generateSums(index + 1, end, currentSum, v, sums);
    generateSums(index + 1, end, currentSum + v[index], v, sums);
}

int main(){
    int n;
    long long x;
    cin >> n >> x;

    vector<int> v(n, 0);
    for(int& i : v){
        cin >> i;
    }

    vector<long long> firstHalf;
    vector<long long> secondHalf;
    int mid = n / 2;

    generateSums(0, mid, 0, v, firstHalf);

    long long count = 0;
    generateSums(mid, n, 0, v, secondHalf);

    sort(secondHalf.begin(), secondHalf.end());
    
    // for(auto& [first, second]: firstHalf){
    //     cout << first << " " << second << endl;
    // }

    // cout << "\n";

    // for(auto& [first, second]: secondHalf){
    //     cout << first << " " << second << endl;
    // }

    for(int i = 0; i < firstHalf.size(); i++){
        count += upper_bound(secondHalf.begin(), secondHalf.end(), x - firstHalf[i]) - lower_bound(secondHalf.begin(), secondHalf.end(), x - firstHalf[i]);
    }

    cout << count << endl;
}