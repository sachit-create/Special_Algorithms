#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void bucket_sort(float* arr, int n) {
    if (n <= 1) return;

    vector<vector<float>> bucket(n);

    for (int i = 0; i < n; ++i) {
        int idx = min(n - 1, int(arr[i] * n));
        bucket[idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (!bucket[i].empty()) {
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)bucket[i].size(); ++j) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    float arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bucket_sort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << fixed << setprecision(3) << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
