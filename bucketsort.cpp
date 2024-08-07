#include <iostream>
#include <vector>
using namespace std;

void bucket_sort(float *arr , int n){
   vector<int> v(n);
  for(int i=0 ; i<n ; i++){
      float idx = arr[i] * n;
      v[idx] = arr[i];
  }
}
int main(){
    int n;
    cin >> n;
    float arr[n];
    for(int i=0; i<n ; i++){
      cin >> arr[i];
    }

    bucket_sort(arr,n);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}