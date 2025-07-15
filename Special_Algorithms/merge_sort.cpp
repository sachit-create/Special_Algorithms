#include <iostream>
using namespace std;

// Merge sort algorithm. time complexity worst case -> 0(nlogn).

// func for merge two halfs orderly.
void merge(int *arr , int l , int mid , int r){
    // size of temporary array.
       int n1 = mid-l+1;
       int n2 = r-mid;
    // creating two holding array;
       int a[n1];
       int b[n2];
    // putting the halfs in it.
    for(int i=0 ; i<n1 ; i++){
        a[i] = arr[l+i];
    }
    for(int j=0 ; j<n2 ; j++){
        b[j] = arr[mid+1+j];
    }
//    f       s      merge/output.
    int i=0 , j=0 , k=l;

    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }

    while(i<n1){
        arr[k++] = a[i++];
    }

    while(j<n2){
        arr[k++] = a[j++];
    }
}
// func for recursively sort array.
void merge_sort(int *arr , int l , int r){
    //base case.
     if(l>=r) return;
     // mid point.
     int mid = (l+r)/2;
     // first half array.
     merge_sort(arr,l,mid);
     // second half array.
     merge_sort(arr,mid+1,r);
     // merging 1 and 2.
     merge(arr,l,mid,r);
}

int main(){
    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    merge_sort(arr , 0 , n-1);

    for(int i=0 ; i<n ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}