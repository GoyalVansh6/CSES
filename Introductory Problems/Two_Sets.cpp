#include<bits/stdc++.h>
using namespace std;

void print(vector<int>& v){
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    long long n;
    cin >> n;
    long long total = (n * (n + 1)) / 2;

    if(total & 1){
        cout << "NO" << endl;
        return 0;
    }

    long long target = total / 2;

    vector<int> first;
    vector<int> second;

    for(int i = n; i >= 1; i--){
        if(target >= i){
            target -= i;
            first.push_back(i);
        }
        else{
            second.push_back(i);
        }
    }
    
    cout << "YES" << endl;
    cout << first.size() << endl;
    print(first);
    cout << second.size() << endl;
    print(second);

    return 0;
}