#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void count_sort(vector<int>& v) {
    if (v.empty()) return;

    int minVal = *min_element(v.begin(), v.end());
    int maxVal = *max_element(v.begin(), v.end());
    int range = maxVal - minVal + 1;

    vector<int> freq(range, 0);
    for (int x : v) {
        freq[x - minVal]++;
    }

    for (int i = 1; i < range; ++i) {
        freq[i] += freq[i - 1];
    }

    vector<int> ans(v.size());
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        int x = v[i];
        ans[--freq[x - minVal]] = x;
    }

    v = ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    count_sort(v);

    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
