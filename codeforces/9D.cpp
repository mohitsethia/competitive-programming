#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
vector<vector<ll> > dp(51, vector<ll>(51, -1));
ll solve(int n, int h){
    if(h < 0 || n < 0){
        return 0;
    }
    if(n == 0) return 1;
    if(h == 0) return n == 1;
    if(dp[n][h] != -1) return dp[n][h];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += solve(n-i, h-1)*solve(i-1, h-1);
    }
    dp[n][h] = ans;
    return ans;
}
int main(){
    int n, h;
    cin >> n >> h;
    cout << solve(n, 50) - solve(n, h-2);
    return 0;
}
