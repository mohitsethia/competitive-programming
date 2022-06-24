#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int l = 0, r = n-1;
        while(s[l] != '*' && l < n) l++;
        while(s[r] != '*' && r >= 0) r--;
        int res = 0;
        s[l] = 'x';
        res++;
        if(s[r] == 'x') {
            cout << res << "\n";
            continue;
        }
        s[r] = 'x';
        res++;
        while(r-l > k) {
            for(int i = l+k; i > l; i--) {
                if(s[i] == '*') {
                    s[i] = 'x';
                    l = i;
                    res++;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
