#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int f(int x){
    if(x <= 1) return x;
    int cnt[2] = {0};
    int c = 1;
    int flag = 1;
    while(1){
        cnt[flag] += c;
        flag ^= 1;
        c *= 2;
        if(cnt[0] + cnt[1] + c > x) break;
    }
    cnt[flag] += x- (cnt[0]+cnt[1]);
    return ((((1+cnt[0]) % MOD) *(cnt[0] % MOD))%MOD + ((cnt[1]%MOD)*(cnt[1]%MOD))%MOD)%MOD;
}

int32_t main(){
    int l, r;
    cin >> l >> r;
    cout << (f(r)-f(l-1)+MOD)%MOD << "\n";
    return 0;
}
