#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll n = s.length();
    if(n == 1 && s[0] == 'm' || s[0] == 'w'){
        cout << "0\n";
        return 0;
    }
    ll dp[n+2];
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(s[i-2] == 'm' || s[i-2] == 'w' || s[i-1] == 'm' || s[i-1] == 'w'){
            cout << "0\n";
            return 0;
        }
        if(s[i-1] == s[i-2] && (s[i-1] == 'u' || s[i-1] == 'n')){
            (dp[i] = dp[i-1] + dp[i-2]) %= mod;
        }
        else{
            (dp[i] = dp[i-1]) %= mod;
        }
    }
    cout << dp[n]%mod << endl;
    return 0;
}
