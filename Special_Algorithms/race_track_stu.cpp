#include <iostream>
using namespace std;

bool canplace_students(int *arr ,int n, int s , int mid){
     int student = 1;
     int lastplaced = arr[0];
     for(int i=0; i<n ; i++){
        if(arr[i] - lastplaced >= mid){
            student++;
            lastplaced = arr[i];
            if(student==s){
                return true;
            }

        }
     }
     return false;
}

int race(int *arr , int n , int s){
    
    int l = 0;
    int r = arr[n-1] - arr[0];
    int ans = -1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(canplace_students(arr,n,s,mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    int s;
    cin >> s;

    cout << race(arr,n,s) << endl;
    return 0;
}