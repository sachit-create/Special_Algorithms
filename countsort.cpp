#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void count_sort(vector<int> &v){
    int n = v.size();

    int max = INT_MIN;
    for(int i=0; i<n ; i++){
        if(max < v[i]){
           max = v[i];
        }
    }
    
    vector<int> freq(max+1,0);
    // creating frequency array.
    for(int i=0 ; i<n ; i++){
        freq[v[i]]++;
    }

    //calculate comulative frequency.
    for(int i=1 ; i<=max ; i++){
        freq[i]+=freq[i-1];
    }

    //caluclating sorted array.
    vector<int> ans(n);
    for(int i=n-1 ; i>=0 ; i--){
        ans[--freq[v[i]]] = v[i];
    }

    //copying the ans array to given array.
    for(int i=0 ; i<n ; i++){
        v[i] = ans[i];
    }

}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i]; 
    }

    count_sort(v);
    
    for(int i=0; i<n ; i++){
        cout << v[i] << " ";
    } 

    return 0;
}