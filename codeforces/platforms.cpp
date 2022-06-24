#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, d, m, l;
    cin >> n >> d >> m >> l;
    ll pos = 0;
    ll cnt = 0;
    ll x, y;
    for(int k = 1; k <= n; k++){
        x = (k -1)*m;
        y = x + l;
        if(pos < x){
            cout << pos << endl;
            return 0;
        }
        pos += ((y-pos)/d)*d;
        while(pos <= y){
            pos += d;
        }
    }
    while(pos <= y){
        pos += d;
    }
    cout << pos << endl;
    return 0;
}
