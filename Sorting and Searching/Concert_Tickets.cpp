#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int,int> ticketPrices;
    for(int i = 0; i < n; i++){
        int price;
        cin >> price;
        ticketPrices[price]++;
    }

    vector<int> sellingPrices;
    sellingPrices.reserve(m);

    for(int i = 0; i < m; i++){
        int offer;
        cin >> offer;

        auto it = ticketPrices.upper_bound(offer);
        if(it != ticketPrices.begin()) {
            --it;
            sellingPrices.push_back(it->first);

            if(it->second > 1) it->second--;
            else ticketPrices.erase(it);
        }
        else sellingPrices.push_back(-1);
    }

    for(int price : sellingPrices){
        cout << price << endl;
    }

    return 0;
}
