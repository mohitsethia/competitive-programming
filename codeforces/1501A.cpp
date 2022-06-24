#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll test = 1;
    cin >> test;
    while(test--){
        ll n;
        cin >> n;
        vector<ll> a(n+1), b(n+1), t(n+1);
        for(ll i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
        }
        for(ll i = 1; i <= n; i++){
            cin >> t[i];
        }
        ll total = 0, last = 0;
        for(ll i = 1; i <= n; i++){
            total += (a[i]-last) + t[i];
            if(i < n){
                total += (b[i]-a[i]+1)/2;
            }
            if(total < b[i] && i < n) total = b[i];
            last = b[i];
        }
        cout << total << "\n";
    }
    return 0;
}
