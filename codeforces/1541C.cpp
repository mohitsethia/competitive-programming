#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>

using namespace std;
using ll = long long;

#define vi vector<ll>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define mk make_pair
#define pii pair<int, pair<int, int> >
#define mi map<int, int>

void solve(){
    ll n;
    cin >> n;
    vi a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n <= 2){
        cout << "0\n";
        return;
    }
    else{
        sort(a.begin(), a.end());
        ll ans = 0;
        for(ll i = 0; i < n-1; i++){
            ll diff = a[i+1]-a[i];
            ans += -diff*(i+1)*(n-i-1) + diff;
        }
        cout << ans << endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
