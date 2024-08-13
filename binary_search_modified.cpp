#include <iostream>
using namespace std;
// this code will gives us the index of a target within time complexity of O(logn),
//for the input like [0,0,0,1,1,1,2,2,3,3,3].
int target_sorted_rotated_duplicate(int *arr, int t, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if the middle element is the target
        if (arr[mid] == t) return mid;

        // If the leftmost, middle, and rightmost elements are the same, skip duplicates
        if (arr[l] == arr[mid] && arr[mid] == arr[r]) {
            l++;
            r--;
        }
        // If the left half is sorted
        else if (arr[l] <= arr[mid]) {
            if (arr[l] <= t && t < arr[mid]) {
                r = mid - 1; // target is in the left half
            } else {
                l = mid + 1; // target is in the right half
            }
        }
        // If the right half is sorted
        else {
            if (arr[mid] < t && t <= arr[r]) {
                l = mid + 1; // target is in the right half
            } else {
                r = mid - 1; // target is in the left half
            }
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {4, 4, 5, 1, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int index = target_sorted_rotated_duplicate(arr, target, 0, n - 1);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}