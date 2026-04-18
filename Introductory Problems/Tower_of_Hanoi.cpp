#include<bits/stdc++.h>
using namespace std;

void fxn(int n, int src, int dest, int aux){
    if(n == 1){
        cout << src << " " << dest << endl;
        return;
    }
    fxn(n-1, src, aux, dest);
    cout << src << " " << dest << endl;
    fxn(n-1, aux, dest, src);
}

int main(){
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << endl;
    fxn(n, 1, 3, 2);
}