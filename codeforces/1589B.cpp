#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        auto get = [](int n, int m){
            int ans = (m/3)*n;
            ans += ((n/3) + min(1ll, n%3))*(m%3);
            return ans;
        };
        int n, m;
        cin >> n >> m;
        cout << min(get(n, m), get(m, n)) << "\n";
    }
    return 0;
}
