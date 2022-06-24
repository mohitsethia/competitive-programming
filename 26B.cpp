#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    string t;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ')') {
            if(t.back() == '(') {
                t.pop_back();
            }
            else {
                t.push_back(s[i]);
            }
        }
        else {
            t.push_back(s[i]);
        }
    }
    cout << s.length()-t.length() << "\n";
    return 0;
}
