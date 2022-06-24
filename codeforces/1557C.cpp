#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

const int MOD = 1e9+7;

int mod_power(int base, int exp){
    if(base == 0) return 0;
    int res = 1;
    while(exp){
        if(exp&1){
            res = (res*base)%MOD;
        }
        (base *= base) %= MOD;
        exp >>= 1;
    }
    return res;
}

int solve(int n, int k){
    if(k == 0) return 1;
    if(n%2 == 0){
        int res = mod_power(2, n*(k-1));
        res += (mod_power(2, n-1) - 1)*solve(n, k-1);
        res %= MOD;
        return res;
    }
    else{
        int res = solve(n, k-1)*(mod_power(2, n-1)+1);
        res %= MOD;
        return res;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }
    return 0;
}
