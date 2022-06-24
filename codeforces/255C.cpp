#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n+1];
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll mx = 0;
    ll dp[n+1][n+1];
    dp[0][0] = 0;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0, last = 0; j < i; j++){
            dp[j][i] = dp[last][j]+1;
            if(a[i] == a[j]) last = j;
            mx = max(mx, dp[j][i]);
        }
    }
    cout << mx << "\n";
    return 0;
}
