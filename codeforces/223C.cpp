#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int MOD = 1e9+7;

int fast_pow(int base, int exp){
    int res = 1;
    while(exp){
        if(exp&1){
            (res *= base) %= MOD;
        }
        (base *= base) %= MOD;
        exp >>= 1;
    }
    return res;
}

vector<int> z(2005);
vector<int> ans(2005);

int32_t main(){
    int n, k;
    cin >> n >> k;
    int x = 1;
    for(int i = 0; i < 2002; i++){
        z[i] = x;
        x = x*(k+i)%MOD * fast_pow(i+1, MOD-2) % MOD;
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            ans[j+i] = (ans[j+i] + z[j] * a[i] % MOD) % MOD;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
