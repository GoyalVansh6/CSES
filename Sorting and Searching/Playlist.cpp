#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, int> freq;
    freq.reserve(2 * n);
    int left = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;

        while (freq[arr[right]] > 1) {
            freq[arr[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;
}
