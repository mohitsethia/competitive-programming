#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int mod = 998244353;

int fast_exp(int base, int exp){
    int res = 1;
    while(exp){
        if(exp&1){
            (res *= base) %= mod;
        }
        (base *= base) %= mod;
        exp >>= 1;
    }
    return res;
}

int modInv(int n){
    return fast_exp(n, mod-2);
}

int32_t main(){
    int n;
    cin >> n;
    vector<int> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % mod;
    }
    cout << (fib[n] * modInv(fast_exp(2, n)%mod)%mod)%mod << "\n";
    return 0;
}
