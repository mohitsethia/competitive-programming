#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
ll nCr(ll n, int r){
    if(r > n-r){
        r = n-r;
    }
    ll res = 1;
    for(int i = 0; i < r; i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans = nCr(n, 5) + nCr(n, 6) + nCr(n, 7);
    cout << ans << endl;
    return 0;
}
