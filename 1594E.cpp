#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int MOD = 1e9+7;

int fast_power(int base, int exp){
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

int32_t main(){
    int k;
    cin >> k;
    int Nodes = (1ll << k) - 2;
    int ans = fast_power(4, Nodes) % MOD;
    ans *= 6;
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}
