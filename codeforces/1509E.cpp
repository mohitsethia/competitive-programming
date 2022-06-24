#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll power[(ll)1e5+5];
    power[0] = 1;
    power[1] = 1;
    for(ll i = 2; i < (ll)1e5+5; i++){
        power[i] = min((ll)1e18, power[i-1]*2ll);
    }
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(k > power[n]){
            cout << "-1\n";
            continue;
        }
        vector<ll> res;
        for(ll i = 0; i < n; i++){
            res.emplace_back(i+1);
        }
        ll start = 0, end = 0;
        while(start < n){
            end = 1;
            while(k > power[n-start-end]){
                k -= power[n-start-end];
                end++;
            }
            reverse(res.begin()+start, res.begin()+start+end);
            start += end;
        }
        for(ll i = 0; i < n; i++){
            cout << res[i] << " \n"[i == n-1];
        }
    }
    return 0;
}
