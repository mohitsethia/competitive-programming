#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << a[0] << endl;
        return 0;
    }
    if(n == 2){
        cout << max(a[0], a[1]) << endl;
        return 0;

    }
    ll sum = accumulate(a, a+n, 0);
    int dp[n*n][n*n+n];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(ll j = sum; j >= 0; j--){
            dp[i][j] |= (dp[i-1][j] | (j >= a[i-1] ? dp[i-1][j-a[i-1]] : 0));
        }
    }
    ll res = sum;
    if(sum/2 -1 > 0){
        for(ll i = 0; i <= sum; i++){
            if(dp[n][i]){
                res = min(res, max(i, sum-i));
            }
        }
    }
    cout << (res == LLONG_MAX ? sum : res) << endl;
    return 0;
}

