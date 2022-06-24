#include <iostream>
#include <algorithm>

using namespace std;

int count(string s) {
    int ones = 0;
    int zeroes = 0;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == '0') {
            zeroes++;
        }
        else {
            ones++;
        }
    }
    return ones == zeroes ? 0 : min(ones, zeroes);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int ans = count(s);
        char last = s.back();
        s.pop_back();
        ans = max(ans, count(s));
        s += last;
        reverse(s.begin(), s.end());
        s.pop_back();
        reverse(s.begin(), s.end());
        ans = max(ans, count(s));
        cout << ans << "\n";
    }
    return 0;
}
