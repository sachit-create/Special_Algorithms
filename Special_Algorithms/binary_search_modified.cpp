#include <iostream>
using namespace std;

// this code gives the index of a target within O(log n)
// for input like [0,0,0,1,1,1,2,2,3,3,3]
int target_sorted_rotated_duplicate(int* arr, int t, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == t) return mid;

        if (arr[l] == arr[mid] && arr[mid] == arr[r]) {
            l++;
            r--;
        } else if (arr[l] <= arr[mid]) {
            if (arr[l] <= t && t < arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (arr[mid] < t && t <= arr[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 4, 5, 1, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int index = target_sorted_rotated_duplicate(arr, target, 0, n - 1);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}
