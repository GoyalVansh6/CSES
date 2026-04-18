#include<bits/stdc++.h>
using namespace std;

void fxn(){
    long long x, y;
    cin >> x >> y;
    long long Ans = 0;
    if(x > y){
        if(x & 1){
            Ans += (x - 1) * (x - 1) + y;
        }
        else{
            Ans = x * x - y + 1;
        }
    }
    else{
        if(y & 1){
            Ans = y * y - x + 1;
        }
        else{
            Ans = (y - 1) * (y - 1) + x;
        }
    }

    cout << Ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        fxn();
    }
}