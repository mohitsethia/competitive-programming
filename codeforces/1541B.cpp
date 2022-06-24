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
#define mi map<ll, ll>
pair<int, int> a[200001];
void solve(){
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    int cnt = 0;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            ll p = 1ll * a[i].first*a[j].first;
            ll q = a[i].second + a[j].second;
            if(p == q) cnt++;
            if(p > 2*n) break;
        }
    }
    cout << cnt << "\n";
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
