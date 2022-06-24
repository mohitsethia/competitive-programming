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
        string s;
        cin >> s;
        ll n;
        cin >> n;
        vector<ll> b(n);
        for(ll i = 0; i < n; i++){
            cin >> b[i];
        }
        vector<vector<ll> > groups;
        while(1){
            vector<ll> pos;
            for(ll i = 0; i < n; i++){
                if(b[i] == 0){
                    pos.emplace_back(i);
                }
            }
            if(pos.empty()){
                break;
            }
            groups.push_back(pos);
            for(ll i = 0; i < n; i++){
                if(b[i] == 0){
                    b[i] = INT_MAX;
                }
                else{
                    for(ll j: pos){
                        b[i] -= abs(j-i);
                    }
                }
            }
        }
        map<char, ll> cnt;
        for(ll i = 0; i < (ll)s.length(); i++){
            cnt[s[i]]++;
        }
        auto j = cnt.rbegin();
        string t(n, '0');
        for(auto g: groups){
            while((ll)j->second < (ll)g.size()){
                j++;
            }
            for(ll p: g){
                t[p] = j->first;
            }
            j++;
        }
        cout << t << "\n";
    }
    return 0;
}
