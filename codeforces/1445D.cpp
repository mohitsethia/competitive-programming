#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

const int MOD = 998244353;
const int N = 3e5 + 1;
int fc[N];

int fast_exp(int base, int exp = MOD - 2){
    int res = 1;
    while(exp){
        if(exp&1){
            res *= base;
            res %= MOD;
        }
        (base *= base) %= MOD;
        exp >>= 1;
    }
    return res;
}

int nCr(int n, int r){
    if(r > n) return 0;
    int num = fc[n];
    int de = (fast_exp(fc[r]) * fast_exp(fc[n-r])) % MOD;
    int ans = (num*de) % MOD;
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fc[0] = 1;
    vector<int> a(2*n);
    for(int i = 1; i <= 2*n; i++){
        fc[i] = (fc[i-1]*i)%MOD;
        cin >> a[i-1];
    }
    int val = nCr(2*n, n);
    int ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < 2*n; i++){
        a[i] %= MOD;
        if(i >= n){
            ans += a[i];
        }
        else{
            ans += (MOD-a[i]);
        }
        ans %= MOD;
    }

    ans = (ans*val)%MOD;
    cout << ans << "\n";
    return 0;
}
