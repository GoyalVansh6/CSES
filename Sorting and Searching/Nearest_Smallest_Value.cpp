#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> Ans(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(!st.empty()){
            Ans[i] = st.top() + 1;
        }
        st.push(i);
    }

    for(int i = 0; i < n; i++){
        cout << Ans[i] << " ";
    }
    cout << endl;

    return 0;
}