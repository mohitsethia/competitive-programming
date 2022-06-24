#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
        vector<ll> a(n);
        vector<ll> freq(n+1), ans(n);
        vector<vector<ll> > occ(n+1);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++){
            freq[a[i]]++;
            occ[a[i]].push_back(i);
        }
        vector<ll> color;
        for(ll i = 1; i <= n; i++){
            if(freq[i] >= k){
                for(ll j = 0; j < k; j++){
                    ans[occ[i][j]] = j+1;
                }
            }
            else{
                for(ll j = 0; j < freq[i]; j++){
                    color.push_back(occ[i][j]);
                }
            }
        }
        for(ll i = 0; i <= (ll)color.size() - k; i+=k){
            for(ll j = 0; j < k; j++){
                ans[color[i+j]] = j+1;
            }
        }
        for(ll i = 0; i < n; i++){
            cout << ans[i] << " \n"[i == n-1];
        }
    }
    return 0;
}
