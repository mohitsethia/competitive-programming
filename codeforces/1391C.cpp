#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
const int mod = (int)1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll res = 1, fact = 1;
    for(int i = 1; i < n; i++){
        res *= 2;
        fact *= i;
        res %= mod;
        fact %= mod;
    }
    fact *= n;
    fact %= mod;
    fact -= res;
    fact %= mod;
    if(fact < 0) fact += mod;
    cout << fact << endl;
    return 0;
}
