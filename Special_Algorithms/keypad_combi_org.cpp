#include <iostream>
#include <vector>
using namespace std;

void func(string& str, int idx, string result, vector<string>& combi, const vector<string>& v) {
    if (idx == (int)str.size()) {
        combi.push_back(result);
        return;
    }

    int digit = str[idx] - '0';
    if (digit <= 1) {
        func(str, idx + 1, result, combi, v);
        return;
    }

    for (char ch : v[digit]) {
        func(str, idx + 1, result + ch, combi, v);
    }
}

int main() {
    vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = "423";
    vector<string> combi;

    func(str, 0, "", combi, v);
    for (const string& s : combi) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
