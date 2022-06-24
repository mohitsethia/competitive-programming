#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXL = 3*1e5;
ll n;
ll a[2][MAXL+50];
ll dp[MAXL+50];
ll dp1[MAXL+50];
ll dp2[MAXL+50];
ll sum[MAXL+50];

void solve(){
    dp[0] = 0, dp1[n+1] = dp2[n+1] = 0, sum[n+1] = 0;
    for(ll i = 1, num = 0; i <= n; i++, num += 2){
        if(i&1){
            dp[i] = dp[i-1] + num*a[0][i] + (num+1)*a[1][i];
        }
        else{
            dp[i] = dp[i-1] + num*a[1][i] + (num+1)*a[0][i];
        }
    }
    for(ll i = n; i >= 1; i--){
        ll temp = (i-1)*2;
        ll num = (n-i)*2;
        sum[i] = sum[i+1] + a[0][i] + a[1][i];
        dp1[i] = dp1[i+1] - sum[i+1] + temp*a[0][i] + (temp+num+1)*a[1][i];
        dp2[i] = dp2[i+1] - sum[i+1] + temp*a[1][i] + (temp+num+1)*a[0][i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    solve();
    ll ans = 0;
    for(ll i = 0 ; i <= n; i++){
        if(i&1){
            ans = max(ans, dp[i] + dp2[i+1]);
        }
        else{
            ans = max(ans, dp[i] + dp1[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}
