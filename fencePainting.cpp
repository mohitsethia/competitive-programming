#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> ans(m), a(n), b(n), c(m);
        vector<ll> mp[n];
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++){
            cin >> b[i];
            if(a[i] != b[i]){
                mp[b[i]-1].push_back(i);
            }
        }
        for(ll i = 0; i < m; i++){
            cin >> c[i];
        }
        ll last = -1;
        if((ll)mp[c[m-1]-1].size() == 0ll){
            for(ll i = 0; i < n; i++){
                if(b[i] == c[m-1]){
                    last = i;
                    break;
                }
            }
        }
        else{
            last = mp[c[m-1]-1].back();
            mp[c[m-1]-1].pop_back();
        }
        if(last == -1){
            cout << "NO\n";
            continue;
        }
        ans[m-1] = last;
        for(ll i = 0; i < m-1; i++){
            if((ll)mp[c[i]-1].size() == 0ll){
                ans[i] = last;
            }
            else{
                ans[i] = mp[c[i]-1].back();
                mp[c[i]-1].pop_back();
            }
        }
        bool ok = true;
        for(ll i = 0; i < n; i++){
            if((ll)mp[i].size() > 0ll){
                ok = false;
                break;
            }
        }
        if(!ok)
            cout << "NO\n";
        else{
            cout << "YES\n";
            for(ll i = 0; i < m; i++){
                cout << ans[i]+1 << " \n"[i == m-1];
            }
        }
    }
    return 0;
}
