#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> values(n);
    vector<int> indexValues(n);

    for(int i = 0; i < n; i++){
        cin >> values[i];
        indexValues[i] = i;
    }

    sort(indexValues.begin(), indexValues.end(), [&](int a, int b){
        return values[a] < values[b];
    });

    vector<int> sortedValues = values;
    sort(sortedValues.begin(), sortedValues.end());

    int left = 0, right = n - 1;

    while(left < right){
        int sum = sortedValues[left] + sortedValues[right];
        if(sum == x){
            cout << indexValues[left] + 1 << " " << indexValues[right] + 1 << endl;
            return 0;
        } else if(sum < x){
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
}
