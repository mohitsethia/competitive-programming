#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int mod = (int)1e9 + 7;
const int N = 2010;
vector<vector<ll> > dp(N, vector<ll>(N, 0));
void precompute(){
    dp[0][1] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            for(int k = j; k < N; k += j){
                (dp[i][k] = dp[i][k] + dp[i-1][j]) %= mod;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    ll n, k;
    cin >> n >> k;
    ll ans = 0ll;
    for(int i = 1; i <= n; i++){
        (ans += dp[k][i]) %= mod;
    }
    cout << ans << endl;
    return 0;
}
