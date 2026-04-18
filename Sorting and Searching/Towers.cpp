#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> k(n, 0);
    for(int& i : k){
        cin >> i;
    }

    vector<int> temp;

    for(int i : k){
        auto itr = upper_bound(temp.begin(), temp.end(), i);
        if(itr == temp.end()){
            temp.push_back(i);
        }
        else{
            *itr = i;
        }
    }

    cout << temp.size();
}