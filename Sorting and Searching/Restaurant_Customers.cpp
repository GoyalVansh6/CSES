#include<bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> arrivalTime(n, 0);
    std::vector<int> leavingTime(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> arrivalTime[i] >> leavingTime[i];
    }

    std::sort(arrivalTime.begin(), arrivalTime.end());
    std::sort(leavingTime.begin(), leavingTime.end());

    int arrival = 0;
    int leaving = 0;
    int currCust = 0;
    int maxCust = 0;

    while(arrival < n && leaving < n){
        if(arrivalTime[arrival] < leavingTime[leaving]){
            currCust++;
            maxCust = std::max(currCust, maxCust);
            arrival++;
        }
        else if(arrivalTime[arrival] > leavingTime[leaving]){
            currCust--;
            leaving++;
        }
        else{
            arrival++;
            leaving++;
        }
    }

    std::cout << maxCust;
}