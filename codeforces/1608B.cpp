#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if(abs(a-b) > 1 || a+b+2 > n) {
            cout << "-1\n";
            continue;
        }
        int c = 0, d = n-1;
        vector<int> res;
        if(a >= b) {
            res.push_back(0);
            c++;
            while(a || b) {
                if(a > 0) {
                    res.push_back(d);
                    d--;
                    a--;
                }
                if(b > 0) {
                    res.push_back(c);
                    c++;
                    b--;
                }
            }
        }
        else {
            res.push_back(n-1);
            d--;
            while(a || b) {
                if(b > 0) {
                    res.push_back(c);
                    c++;
                    b--;
                }
                if(a > 0) {
                    res.push_back(d);
                    d--;
                    a--;
                }
            }
        }
        if(res.back() == c-1) {
            for(int i = c; i <= d; i++) {
                res.push_back(i);
            }
        }
        else {
            for(int i = d; i >= c; i--) {
                res.push_back(i);
            }
        }
        for(int x: res) {
            cout << x+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
