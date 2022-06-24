#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll mx = 1e5;
vector<ll> factors[mx+5];
ll dp[mx+5];
ll x[mx+5];
void sieve(){
    for(int i = 2; i <= mx; i++){
        if(!x[i]){
            factors[i].emplace_back(i);
            for(int j = i+i; j <= mx; j += i){
                x[j] = 1;
                factors[j].emplace_back(i);
            }
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    sieve();
    ll n;
    cin >> n;
    ll dp[100001] = {0}, d[100001] = {0};
    ll ans = 0;
    ll a;
    for(ll i = 0; i < n; i++){
        cin >> a;
        dp[a] = d[a] = 1;
        for(ll j = 2; j*j <= a; j++){
            if(a%j == 0){
                dp[a] = max(dp[a], d[j]+1);
                dp[a] = max(dp[a], d[a/j] + 1);
            }
        }
        for(ll j = 2; j*j <= a; j++){
            if(a%j == 0){
                d[j] = dp[a];
                d[a/j] = dp[a];
            }
        }
        ans = max(ans, dp[a]);
    }
    cout << ans << "\n";




    /*
    ll x, maxi;
    while(n--){
        cin >> x;
        maxi = 0;
        for(int i = 0; i < (int)factors[x].size(); i++){
            maxi = max(maxi, dp[factors[x][i]]);
        }
        for(int i = 0; i < (int)factors[x].size(); i++){
            dp[factors[x][i]] = maxi+1;
        }
    }
        maxi = 1;
        for(int i = 2; i <= mx; i++){
            maxi = max(maxi, dp[i]);
        }
        cout << maxi << "\n";
    */
    return 0;
}
