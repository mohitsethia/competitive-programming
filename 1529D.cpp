#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int mod = 998244353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> divisors(n+1);
    for(ll i = 2; i <= n; i++){
        for(ll j = i; j <= n; j += i){
            divisors[j]++;
        }
    }
    vector<ll> dp(n+1, 0);
    dp[1] = 1;
    ll sum = 1;
    for(ll i = 2; i <= n; i++){
        dp[i] += sum + divisors[i]+1;
        dp[i] %= mod;
        sum += dp[i];
        sum %= mod;
    }
    cout << dp[n] << '\n';
    return 0;
}
