#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
vector<vector<ll> > dp(1000002, vector<ll>(2, 0));
// 0 -> represent width 1 tile
// 1 -> represent width 2 tile
void calc(){
    ll n = 1000000;
    dp[n+1][0] = dp[n+1][1] = 1;
    for(int i = n; i >= 2; i--){
        ll op1 = (dp[i+1][1]+dp[i+1][0])%mod;   //not extending any tile
        ll op2 = dp[i+1][0];                    //extending both 1 width tile
        ll op3 = (2*dp[i+1][0])%mod;            //extending either of 1 width tile
        ll op4 = dp[i+1][1];                    //extending tile of 2 width
        dp[i][0] = (op1+op2+op3)%mod;           
        dp[i][1] = (op1+op4)%mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    calc();
    int t = 1;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << (dp[1000000 - n + 2][0] + dp[1000000 - n + 2][1])%mod << endl;
    }
    return 0;
}
