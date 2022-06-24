#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> x(n);
        for(ll i = 0; i < n; i++){
            cin >> x[i];
        }
        ll y;
        for(ll j = 0; j < n; j++){
            cin >> y;
        }
        sort(x.begin(), x.end());
        vector<ll> l(n), r(n);
        ll i = 0, j = 0;
        while(j < n){
            if(x[j]-x[i] <= k){
                if(j){
                    r[j] = max(r[j-1], j-i+1);
                }
                else{
                    r[j] = j-i+1;
                }
                j++;
            }
            else{
                i++;
            }
        }
        i = j = n-1;
        while(j >= 0){
            if(x[i]-x[j] <= k){
                if(j+1 < n){
                    l[j] = max(l[j+1], i-j+1);
                }
                else{
                    l[j] = i-j+1;
                }
                j--;
            }
            else{
                i--;
            }
        }
        ll ans = 1;
        for(ll i = 0; i < n-1; i++){
            ans = max(ans, r[i]+l[i+1]);
        }
        cout << ans << "\n";
    }
    return 0;
}
