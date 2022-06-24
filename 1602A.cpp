#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        char ch = 'z';
        for(int i = 0; i < s.length(); i++) {
            ch = min(ch, s[i]);
        }
        string res = "";
        bool deleted = false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ch && !deleted) {
                deleted = true;
                continue;
            }
            res += s[i];
        }
        cout << ch << " " << res << "\n";
    }
    return 0;
}
