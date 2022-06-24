#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
#define mod 1000000007
int power(int base, int exponent){
    int ans = 1;
    while(exponent > 0){
        if(exponent&1){
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exponent /= 2;
    }
    return ans;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = power(2, n-1);
        cout << ans << endl;
    }
    return 0;
}
