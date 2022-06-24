#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll w_fixed, h_fixed;
        cin >> w_fixed >> h_fixed;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll w, h;
        cin >> w >> h;
        if(h+(y2-y1) > h_fixed && w+(x2-x1) > w_fixed){
            cout << "-1\n";
            continue;
        }
        ll mn = LLONG_MAX;
        if(h+(y2-y1) <= h_fixed){
            mn = min(mn, max(0ll, h-y1));
            mn = min(mn, max(0ll, y2-h_fixed+h));
        }
        if(w+(x2-x1) <= w_fixed){
            mn = min(mn, max(0ll, w-x1));
            mn = min(mn, max(0ll, x2-w_fixed+w));
        }
        long double ans = 1.0*mn;
        cout << fixed << setprecision(10) << ans << "\n";
    }
    return 0;
}
