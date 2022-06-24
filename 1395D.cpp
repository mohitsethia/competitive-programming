#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, d, m;
    scanf("%lld%lld%lld", &n, &d, &m);
    vector<ll> small(n+2), big(n+2);
    ll x;
    for(ll i = 0; i < n; i++){
        scanf("%lld", &x);
        if(x > m){
            big.emplace_back(x);
        }
        else{
            small.emplace_back(x);
        }
    }
    sort(small.begin(), small.end(), greater<ll>());
    sort(big.begin()+1, big.end(), greater<ll>());
    for(ll i = 1; i < (ll)big.size(); i++){
        big[i] += big[i-1];
        // cout << big[i] << " ";
    }
    // cout << "\n";
    ll ans = 0ll;
    ll smallBonus = 0ll;
    for(ll i = 0; i <= n; i++){
        ll rem = n-i;
        ll takenBig = (rem+d)/(d+1);
        ll bigBonus = big[takenBig];
        ans = max(ans, bigBonus + smallBonus);
        
        smallBonus += small[i];
    }
    printf("%lld", ans);
    return 0;
}
