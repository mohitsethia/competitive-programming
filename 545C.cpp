#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll> > a(n+2);
    for(ll i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    a[0].first = -1ll * (ll)1e18;
    a[n+1].first = (ll)1e18;
    ll sum = 0;
    for(ll i = 1; i <= n; i++){
        if(a[i].first-a[i].second > a[i-1].first){
            sum++;
        }
        else if(a[i].first + a[i].second < a[i+1].first){
            sum++;
            a[i].first += a[i].second;
        }
    }
    cout << sum << endl;
    return 0;
}
