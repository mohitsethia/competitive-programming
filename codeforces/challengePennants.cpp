#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
ll nCr(ll n, ll r){
    if(r > n-r){
        r = n-r;
    }
    ll res = 1;
    for(ll i = 0; i < r; i++){
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
    //k = 5 types of "I fixed a critical bug"
    ll k = 5;
    ll comb1 = nCr(n+k-1, n-1);
    //k = 3 types of "I suggested a new feature"
    k = 3;
    ll comb2 = nCr(n+k-1, n-1);
    ll total = comb1*comb2;
    cout << total << endl;
    return 0;
}
