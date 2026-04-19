#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first.first >> intervals[i].first.second;
        intervals[i].second = i;
    }

    sort(intervals.begin(), intervals.end());

    int rooms = 0;
    vector<int> assignment(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top().first < intervals[i].first.first) {
            int room_id = pq.top().second;
            pq.pop();
            pq.push({intervals[i].first.second, room_id});
            assignment[intervals[i].second] = room_id;
        } else {
            rooms++;
            pq.push({intervals[i].first.second, rooms});
            assignment[intervals[i].second] = rooms;
        }
    }

    cout << rooms << endl;
    for (int i = 0; i < n; i++) {
        cout << assignment[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}