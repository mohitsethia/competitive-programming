#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

#define int long long

const int MOD = 1e9 + 7;

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

int32_t main(){
    int x, n;
    cin >> x >> n;
    set<int> pr;
    for(int i = 2; i*i <= x; i += (i&1)+1){
        if(!(x%i)){
            pr.insert(i);
            while(x%i == 0) x /= i;
        }
    }
    if(x > 1){
        pr.insert(x);
    }
    int ans = 1;
    for(auto e: pr){
        int p = 0;
        int num = n;
        while(num){
            p += num/e;
            num /= e;
        }
        ans *= fast_pow(e, p);
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}
