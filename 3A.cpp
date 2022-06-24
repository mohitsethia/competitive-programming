#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<string> ans;
    if(s[0] == t[0]) {
        while(s[1] < t[1]) {
            ans.push_back("U");
            s[1]++;
        }
        while(s[1] > t[1]) {
            ans.push_back("D");
            s[1]--;
        }
    }
    else if(s[0] < t[0]) {
        while(s[1] < t[1] && s[0] < t[0]) {
            ans.push_back("RU");
            s[1]++;
            s[0]++;
        }
        while(s[1] > t[1] && s[0] < t[0]) {
            ans.push_back("RD");
            s[1]--;
            s[0]++;
        }
        while(s[1] == t[1] && s[0] < t[0]) {
            ans.push_back("R");
            s[0]++;
        }
        while(s[1] < t[1] && s[0] == t[0]) {
            ans.push_back("U");
            s[1]++;
        }
        while(s[1] > t[1] && s[0] == t[0]) {
            ans.push_back("D");
            s[1]--;
        }
    }
    else{
        while(s[1] < t[1] && s[0] > t[0]) {
            ans.push_back("LU");
            s[1]++;
            s[0]--;
        }
        while(s[1] > t[1] && s[0] > t[0]) {
            ans.push_back("LD");
            s[1]--;
            s[0]--;
        }
        while(s[1] == t[1] && s[0] > t[0]) {
            ans.push_back("L");
            s[0]--;
        }
        while(s[1] < t[1] && s[0] == t[0]) {
            ans.push_back("U");
            s[1]++;
        }
        while(s[1] > t[1] && s[0] == t[0]) {
            ans.push_back("D");
            s[1]--;
        }
    }
    cout << ans.size() << "\n";
    for(auto str: ans) {
        cout << str << "\n";
    }
    return 0;
}
