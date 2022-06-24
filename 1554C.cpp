#include<iostream>
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
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        ll last = 31;
        while(last > 0){
            for(ll i = 0; i < 32; i++){
                ll x = n|((1<<i)-1);
                if(x > m){
                    ans |= (1<<i)/2;
                    n |= (1 << i)/2;
                    last = i;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
