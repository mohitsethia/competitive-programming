#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
#define pb push_back
#define pi pair<ll, ll>
#define vi vector<ll>
#define vii vector<vector<ll> >
#define vpi vector<pi>
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vpi p(n);
    for(ll i = 0; i < n; i++){
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    ll s = 0, e = n-1;
    ll ans = 0, bought = 0;
    while(s <= e){
        if(p[s].first <= bought){
            bought += p[s].second;
            ans += p[s].second;
            s++;
        }
        else{
            ll req = min((p[s].first-bought), p[e].second);
            bought += req;
            p[e].second -= req;
            ans += 2*req;
            if(p[e].second == 0){
                e--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
