#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = long long;
ll distance(ll x1, ll y1, ll x2, ll y2){
    ll res = abs(x2-x1) + abs(y2-y1);
    return res;
}
void solve(){
    ll n, m, s, e;
    cin >> n >> m >> s >> e;
    if(n == 1 && m == 1){
        cout << "1 1 1 1\n";
        return;
    }
    if((s <= n/2 && e <= m/2) || (s >= n/2 && e >= m/2)){
        cout << n << " 1 1 " << m << "\n";
        return;
    }
    cout << n << " " <<  m << " 1 1\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
