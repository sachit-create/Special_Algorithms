#include <iostream>
#include <vector>
#include <string>

using namespace std;

void selectionSort(vector<string>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<string> fruits = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};
    
    selectionSort(fruits);
    
    cout << "Sorted fruits: ";
    for (const auto& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;
    
    return 0;
}