#include<iostream>
#include<cstdio>
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
        ll n;
        cin >> n;
        vector<ll> odd, even;
        ll x;
        for(int i = 1; i <= 2*n; i++){
            cin >> x;
            if(x%2){
                odd.push_back(i);
            }
            else{
                even.push_back(i);
            }
        }
        vector<pair<ll, ll> > ans;
        for(int i = 0; i < (ll)odd.size() -1; i+=2){
            ans.push_back({odd[i], odd[i+1]});
        }
        for(int j = 0; j < (ll)even.size()-1; j+=2){
            ans.push_back({even[j], even[j+1]});
        }
        for(int i = 0; i < n-1; i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}
