#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int min_cost(const vector<int>& arr, int idx, vector<int>& dp) {
    int n = arr.size();
    if (n <= 1 || idx >= n) return 0;
    if (idx == n - 1) return 0;
    if (dp[idx] != -1) return dp[idx];

    int best = INT_MAX;

    if (idx + 1 < n) {
        best = min(best, min_cost(arr, idx + 1, dp) + abs(arr[idx] - arr[idx + 1]));
    }
    if (idx + 2 < n) {
        best = min(best, min_cost(arr, idx + 2, dp) + abs(arr[idx] - arr[idx + 2]));
    }

    return dp[idx] = best;
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(n, -1);
    cout << min_cost(arr, 0, dp) << endl;
    return 0;
}
