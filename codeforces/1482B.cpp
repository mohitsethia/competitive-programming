#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        ll mx = INT_MIN;
        set<ll> s;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
            if(i > 1){
                s.insert(a[i]-a[i-1]);
            }
        }
        if(n <= 2 || s.size() == 1){
            cout << "0\n";
            continue;
        }
        if(s.size() > 2){
            cout << "-1\n";
            continue;
        }
        ll c = *s.begin();
        s.erase(s.begin());
        ll d = *s.begin();
        if((c >= 0 && d >= 0) || (c <= 0 && d <= 0)){
            cout << "-1\n";
            continue;
        }
        if(c < d) swap(c, d);
        if(mx > c-d){
            cout << "-1\n";
            continue;
        }
        cout << c-d << " " << c << "\n";
    }
    return 0;
}
