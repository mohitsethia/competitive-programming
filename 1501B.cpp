#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        vector<ll> dp(n+2);
        for(ll i = 1; i <= n; i++){
            if(a[i] > 0){
                ll left = i-a[i]+1, right = i+1;
                dp[max(1ll, i-a[i]+1)]++;
                dp[right]--;
            }
        }
        for(ll i = 1; i <= n; i++){
            dp[i] += dp[i-1];
            if(dp[i] > 0) cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}
