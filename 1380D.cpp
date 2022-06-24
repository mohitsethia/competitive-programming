#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x, y, k;
    cin >> n >> m;
    cin >> x >> k >> y;
    vector<ll> a(n+2), b(m+2);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 1; i <= m; i++){
        cin >> b[i];
    }
    b[0] = 0;
    b[m+1] = -1;
    a[n] = -1;
    ll pos = 1;
    ll initial = 0;
    ll ans = 0;
    ll mx = -1 * 1ll;
    bool ok = false;
    for(ll i = 0; i <= n; i++){
        if(a[i] == b[pos]){
            ll len = i-initial;
            if(len > 0){
                if(len >= k){
                    if(y*k < x){
                        if(mx < b[pos] || mx < b[pos-1]){
                            ans += len*y;
                        }
                        else{
                            ans += x;
                            ans += (len-k)*y;
                        }
                    }
                    else{
                        ans += y * (len%k);
                        ans += x * (len/k);
                    }
                }
                else{
                    if(b[pos] < mx && b[pos-1] < mx){
                        ok = false;
                        break;
                    }
                    else{
                        ans += len*y;
                    }
                }
            }
            initial = i+1;
            pos++;
            if(pos == m+2){
                ok = true;
                break;
            }
            mx = 0;
        }
        else{
            mx = max(mx, a[i]);
        }
    }
    if(ok) cout << ans << "\n";
    else cout << "-1\n";
    return 0;
}
