#include <iostream>
#include <algorithm>

using namespace std;

bool factorize(int n) {
    vector<int> v;
    for(int i = 2; i*i <= n; i += (i&1)+1) {
        if(n%i == 0) {
            v.push_back(i);
            if(v.size() > 2) return false;
            while(n%i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        v.push_back(n);
    }
    return v.size() == 2;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 4; i <= n; i++) {
        if(factorize(i)) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
