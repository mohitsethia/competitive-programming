#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define int long long

const int MOD = 1e8;
int k1, k2;
int dp[101][101][2];
int solve(int n1, int n2, int t){
    if(n1 + n2 == 0) return 1;
    int &res = dp[n1][n2][t];
    if(res != -1) return res;
    res = 0;
    if(t == 0){
        for(int i = 1; i <= min(k1, n1); i++){
            res += solve(n1-i, n2, 1-t);
            res %= MOD;
        }
    }
    if(t){
        for(int i = 1; i <= min(k2, n2); i++){
            res += solve(n1, n2-i, 1-t);
            res %= MOD;
        }
    }
    return res;
}

int32_t main(){
    memset(dp, -1, sizeof dp);
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << (solve(n1, n2, 0) + solve(n1, n2, 1))%MOD << "\n";
    return 0;
}
