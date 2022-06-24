#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        vector<ll> a(n);
        ll mx = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        if(mx <= d){
            cout << "YES\n";
        }
        else{
            sort(a.begin(), a.end());
            if(a[0]+a[1] <= d){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
