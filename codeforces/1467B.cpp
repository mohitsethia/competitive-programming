#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll ans = 0;
        ll numberOfPeaks = 0;
        vector<ll> peaks(n);
        for(ll i = 1; i < n-1; i++){
            if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])){
                numberOfPeaks++;
                peaks[i]++;
            }
        }
        ans = numberOfPeaks;
        if(ans == 0){
            cout << "0\n";
            continue;
        }
        auto isValley = [&](int i) -> bool{
            return (i > 0 && i < n-1 && a[i] < a[i-1] && a[i] < a[i+1]);
        };
        auto isHill = [&](int i) -> bool{
            return (i > 0 && i < n-1 && a[i] > a[i-1] && a[i] > a[i+1]);
        };
        for(ll i = 1; i < n-1; i++){
            ll temp = a[i];
            a[i] = a[i-1];
            ans = min(ans, numberOfPeaks - peaks[i-1]-peaks[i]-peaks[i+1]+ isHill(i-1) + isValley(i-1) + isHill(i) + isValley(i) + isHill(i+1) + isValley(i+1));
            a[i] = a[i+1];
            ans = min(ans, numberOfPeaks - peaks[i-1]-peaks[i]-peaks[i+1]+ isHill(i-1) + isValley(i-1) + isHill(i) + isValley(i) + isHill(i+1) + isValley(i+1));

            if(ans <= 0) break;
            a[i] = temp;
        }
        cout << (ans < 0 ? 0 : ans) << "\n";
    }
    return 0;
}
