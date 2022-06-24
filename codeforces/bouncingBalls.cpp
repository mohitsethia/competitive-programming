#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, p, k;
        string s;
        cin >> n >> p >> k >> s;
        ll x, y;
        cin >> x >> y;
        ll ans = 1e18;
        p--;
        vector<int> cnt(n);
        for(int i = n-1; i >= 0; i--){
            cnt[i] = (s[i] == '0' ? 1 : 0);
            if(i <= n-k-1){
                cnt[i] += cnt[i+k];
            }
        }
        for(int i = p; i < n; i++){
            ans = min(ans, (i-p)*y + x*cnt[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
