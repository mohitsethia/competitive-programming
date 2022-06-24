#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int mod = (ll)1e9 + 7ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<ll> dp;
    ll n = s.length();
    ll cnt = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] != 'a' && s[i] != 'b'){
            continue;
        }
        if(s[i] == 'a'){
            cnt++;
        }
        else{
            dp.emplace_back(cnt+1);
            cnt = 0;
        }
    }
    if(cnt){
        dp.emplace_back(cnt+1);
    }
    ll ans = 1;
    for(ll i = 0; i < (ll)dp.size(); i++){
        (ans *= dp[i]) %= mod;
    }
    ans--;
    cout << ans << endl;
    return 0;
}
