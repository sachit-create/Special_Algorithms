#include <iostream>
#include <vector>
using namespace std;
// this code will give you the sum of all subsets pesent in the array.
void subset_sum(int *arr , int n , int idx  , int sum, vector<int> &result){
    if(idx == n)  {
        result.push_back(sum);
        return;
    }
    subset_sum(arr , n , idx+1 , sum + arr[idx] , result);//pick element
    subset_sum(arr , n , idx+1 , sum , result);// do not pick element
}

int main(){
    int arr[] = {2,4,5};
    int  n = sizeof(arr) / sizeof(arr[0]);
    vector <int> result;
    int idx =0;
    int sum = 0;
    subset_sum(arr , n , idx , sum , result);
    for(int i = 0 ;i<result.size(); i++ ){
        cout << result[i] << " ";
    }
    return 0;
}