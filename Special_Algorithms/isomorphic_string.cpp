#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isomorphic_check(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) return false;

    vector<int> v1(128, -1);
    vector<int> v2(128, -1);

    for (int i = 0; i < (int)str1.size(); ++i) {
        if (v1[str1[i]] != v2[str2[i]]) {
            return false;
        }
        v1[str1[i]] = v2[str2[i]] = i;
    }

    return true;
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    if (isomorphic_check(str1, str2)) {
        cout << "these strings are isomorphic, YAY!" << endl;
    } else {
        cout << "these strings are not isomorphic!" << endl;
    }
    return 0;
}
