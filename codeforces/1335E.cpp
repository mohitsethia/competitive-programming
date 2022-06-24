#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
ll n, ans = 0;
vector<ll> occ[200];
vector<ll> v;
void solve(){
    ll l = 0, r = (ll)v.size()-1, x = 0, s = 0;
    for(ll a: v){
        s += a;
    }
    ans = max(ans, s);
    while(1){
        ++x;
        bool bl = false, br = false;
        while(l <= r && !bl){
            if(!v[l]){
                bl = true;
            }
            else{
                s--;
            }
            ++l;
        }
        while(l <= r && !br){
            if(!v[r]){
                br = true;
            }
            else{
                --s;
            }
            r--;
        }
        if(!bl || !br) break;
        ans = max(ans, 2*x + s);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll x;
        for(ll i = 0; i < n; i++){
            cin >> x;
            --x;
            occ[x].emplace_back(i);
        }
        for(ll i = 0; i < 200; i++){
            occ[i].emplace_back(n);
        }
        ans = 0;
        for(ll a = 0; a < 200; a++){
            if((ll)occ[a].size() == 1){
                continue;
            }
            for(ll b = 0; b < 200; b++){
                if(a == b){
                    ans = max(ans, (ll)occ[a].size()-1);
                    continue;
                }
                for(ll i = 0, j = 0; i < (ll)occ[a].size()-1 || j < (ll)occ[b].size() - 1; ){
                    if(occ[a][i] < occ[b][j]){
                        v.emplace_back(0);
                        i++;
                    }
                    else{
                        v.emplace_back(1);
                        j++;
                    }
                }
                solve();
                v.clear();
            }
        }
        cout << ans << "\n";
        for(ll i = 0; i < 200; i++){
            occ[i].clear();
        }
    }
    return 0;
}
