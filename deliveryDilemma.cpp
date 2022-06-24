#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
using ll = long long;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll, ll> > v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first;
        }
        for(int j = 0; j < n; j++){
            cin >> v[j].second;
        }
        sort(v.begin(), v.end());
        ll ans = 0, sum = 0;
        for(int i = n-1; i >= 0; i--){
            sum += v[i].second;
            if(sum < v[i].first){
                continue;
            }
            else if(sum > v[i].first){
                ans = max(sum-v[i].second, v[i].first);
                break;
            }
            else{
                ans = v[i].first;
                break;
            }
        }
        if(ans != 0)
            cout << ans << endl;
        else{
            cout << sum << endl;
        }
    }
    return 0;
}
