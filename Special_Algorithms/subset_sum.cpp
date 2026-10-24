#include <iostream>
#include <vector>
using namespace std;

void subset_sum(int* arr, int n, int idx, int sum, vector<int>& result) {
    if (idx == n) {
        result.push_back(sum);
        return;
    }

    subset_sum(arr, n, idx + 1, sum + arr[idx], result);
    subset_sum(arr, n, idx + 1, sum, result);
}

int main() {
    int arr[] = {2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result;

    subset_sum(arr, n, 0, 0, result);
    for (int i = 0; i < (int)result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
