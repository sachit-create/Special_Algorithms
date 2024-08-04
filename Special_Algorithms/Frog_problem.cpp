#include <iostream>
using namespace std;
int min_cost(int *arr ,int n, int idx=0){
 //last stone base case.
 if(idx == n-1){
    return 0;
 }
 // second last stone base case.
 if(idx == n-2){
    return min_cost(arr, n ,idx+1) +abs(arr[idx] - arr[idx+1]);
 }
 // do jump i+1 or i+2 and return after calculate the best minimum result.
 return min(min_cost(arr, n ,idx+1) + abs(arr[idx] - arr[idx+1]) , min_cost(arr, n ,idx+2) + abs(arr[idx] - arr[idx+2]));
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    while(i < n){
     cin >> arr[i];  
     i++;
    }
    cout << min_cost(arr,n);

    return 0;
}