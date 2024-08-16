#include <iostream>
#include <vector>
using namespace std;

bool isomorphic_check(string str1, string str2){
    // time complexity  O(n).
    // space complexity O(1)
    if(str1.length() != str2.length()) return false;// checking length is equal or not.
    else{
       vector<int> v1(128,-1);
       vector<int> v2(128,-1);

       for(int i=0 ; i<str1.size() ; i++){
          if(v1[str1[i]] != v2[str2[i]]){// check if value of character at idx i match in both vectors.
            return false;
          }
          else{
            v1[str1[i]] = v2[str2[i]] = i;// stroring position in vectors for ch at idx i.
          }
       }
    } 
    return true;
}

int main(){
    string str1,str2;
    cin >> str1;
    cin >> str2;

    if(isomorphic_check(str1,str2)){
       cout << "these strings are isomorphic ,YAY!" << endl;
    }
    else{
        cout << "these strings are not isomorphic!"<<endl;
    }
    return 0;
}