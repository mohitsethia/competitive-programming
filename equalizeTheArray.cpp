#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n; 
        cin >> n;
        map<ll, ll> mp;
        ll x, mn = INT_MAX, mx = INT_MIN;
        for(ll i = 0 ;i < n; i++){
            cin >> x;
            mp[x]++;
            mx = max(mx, mp[x]);
        }
        map<ll, ll>::iterator it;
        vector<ll> v;
        for(it = mp.begin(); it != mp.end(); it++){
            v.push_back(it->second);
        }
        sort(v.begin(), v.end());
        mn = n-mp.size();
        for(ll i = 1; i <= mx; i++){
            ll ind = (lower_bound(v.begin(), v.end(), i) - v.begin());
            mn = min((n- (((int)v.size()-ind)*i)), mn);
        }
        cout << mn << endl;
    }
    return 0;
}
