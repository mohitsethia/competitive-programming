#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll ans = n*(n-1)*(n-2)*(n-3)*(n-4);
    ans = ans/120*ans;
    cout << ans << endl;
    return 0;
}
