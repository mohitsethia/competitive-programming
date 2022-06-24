#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int pow(int base, int exp) {
    int res = 1;
    while(exp) {
        if(exp&1) {
            res = res * base;
        }
        base *= base;
        exp >>= 1;
    }
    return res;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s = "";
        while(n > 0) {
            char ch = (n%3) + '0';
            s = ch + s;
            n /= 3;
        }
        s = '0' + s;
        int c1 = 0;
        int idx = 0;
        int c2 = 0;
        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == '0' && c1 == 0) {
                c1 = 1;
                idx = i;
            }
            if(s[i] == '2') {
                c1 = 0;
                c2 = 1;
            }
        }
        if(c1 == 1) {
            if(c2 == 1) {
                s[idx] = '1';
                for(int i = idx+1; i < s.length(); i++) {
                    s[i] = '0';
                }
            }
        }
        else {
            if(c2 == 1) {
                s[0] = '1';
                for(int i = 1; i < s.length(); i++) {
                    s[i] = '0';
                }
            }
        }
        reverse(s.begin(), s.end());
        int num = 0;
        for(int i = 0; i < s.length(); i++) {
            num += pow(3, i) * (s[i]-'0');
        }
        cout << num << "\n";
    }
    return 0;
}
