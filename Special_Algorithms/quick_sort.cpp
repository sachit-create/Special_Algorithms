#include <iostream>
using namespace std;
// time complexity is -> worst-O(n^2) , best - omega(nlogn).
int partition(int *arr  , int f , int l){
    int pivot =  arr[l];
    int i = f-1;
    int j = f;
    for(;j<l ; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // now i is pointing to the last element less than pivot.

    swap(arr[i+1],arr[l]);
    return i+1;
}

void quick_sort(int *arr , int f , int l){
    if(f>=l) return;

    int pi = partition(arr,f,l);
    quick_sort(arr,f,pi-1);
    quick_sort(arr,pi+1,l);
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr,0,n-1);

    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}