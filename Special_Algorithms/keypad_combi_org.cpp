#include <iostream>
#include <vector>
using namespace std;

void func(string &str , int idx , string result , vector<string> &combi , vector<string> &v){
    if(idx == str.size()){
       combi.push_back(result);
       return;
    }
    int digit = str[idx] - '0';
    if(digit <= 1){
        func(str , idx+1 ,result , combi , v);
        return;
    }
    for(int j = 0 ; j < v[digit].size() ; j++){
        func(str , idx+1 , result+v[digit][j] , combi , v);
    }
    return;
}

int main(){
    vector<string>  v (10);
    v =  {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    string str = "423";
    vector<string> combi;
    func(str , 0  , "" , combi , v);
    for(int i = 0 ; i<combi.size() ; i++){
        cout << combi[i] << " ";
    }
    return 0;
}