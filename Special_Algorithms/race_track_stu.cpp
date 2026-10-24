#include <iostream>
#include <vector>
using namespace std;

bool canplace_students(const vector<int>& arr, int students, int minDistance) {
    int placed = 1;
    int lastPlaced = arr[0];

    for (int i = 1; i < (int)arr.size(); ++i) {
        if (arr[i] - lastPlaced >= minDistance) {
            placed++;
            lastPlaced = arr[i];
            if (placed == students) {
                return true;
            }
        }
    }
    return false;
}

int race(const vector<int>& arr, int students) {
    if (students <= 0 || students > (int)arr.size()) return -1;

    int left = 0;
    int right = arr.back() - arr.front();
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canplace_students(arr, students, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int students;
    cin >> students;

    cout << race(arr, students) << endl;
    return 0;
}
