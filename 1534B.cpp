#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
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
        vector<ll> a(n);
        ll total = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i == 0) total += a[i];
            else total += abs(a[i]-a[i-1]);
            if(i == n-1 && i != 0) total += a[i];
        }
        for(int i = 1; i < n-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                total -= a[i]- max(a[i-1], a[i+1]);
                a[i] = max(a[i-1], a[i+1]);
            }
        }
        if(n > 1){
            if(a[0] > a[1]){
                total -= abs(a[0]-a[1]);
            }
            if(a[n-1] > a[n-2]){
                total -= abs(a[n-1]-a[n-2]);
            }
        }
        cout << total << endl;
    }
    return 0;
}
