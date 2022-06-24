#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 1e6+10;
int f[MAXN];
int a, b, n;
int power(int x, int e, int mod){
    int res = 1;
    while(e){
        if(e&1){
            res = (res*x)%mod;
        }
        e /= 2;
        x = (x*x)%mod;
    }
    return res;
}
void factorial(){
    f[0] = f[1] = 1;
    for(int i = 2; i < MAXN; i++){
        f[i] = (f[i-1]*i)%mod;
    }
}
bool is_excellent(int num){
    while(num){
        if(num%10 != a && num%10 != b){
            return false;
        }
        num /= 10;
    }
    return true;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    factorial();
    cin >> a >> b >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int num = a*i + b*(n-i);
        if(is_excellent(num)){
            int T = f[n];
            T = (T*power(f[i], mod-2, mod))%mod;
            T = (T*power(f[n-i], mod-2, mod))%mod;
            ans = (ans+T)%mod;
        }
    }
    cout << ans%mod << endl;
    return 0;
}
