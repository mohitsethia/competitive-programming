#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int ans = 0;
        int n = a.length();
        int m = b.length();
        set<string> st;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                string temp = a.substr(i, j-i+1);
                st.insert(temp);
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = i; j < m; j++) {
                if(st.count(b.substr(i, j-i+1))) {
                    ans = max(ans, j-i+1);
                }
            }
        }
        cout << n+m - 2*ans << "\n";
    }
    return 0;
}
