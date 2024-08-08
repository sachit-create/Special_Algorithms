#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

void bucket_sort(float *arr , int n){
    vector<vector <float> > bucket(n , vector<float> ());

     //step2: inserting elements into bucket.
     for(int i=0 ; i<n ;i++){
      int idx = arr[i]*n;
      bucket[idx].push_back(arr[i]);
     }

     // step3: sorting individual buckets.
     for(int i=0 ; i<n ; i++){
        if(!bucket[i].empty()){
          sort(bucket[i].begin() , bucket[i].end());
        }
     }
     //step4: combining elements from buckets;
     int k = 0;
     for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<bucket[i].size() ; j++){
          arr[k++] = bucket[i][j];
        }
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
        cout <<fixed << setprecision(3) << arr[i] << " ";
    }
    return 0;
}