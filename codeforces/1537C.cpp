#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll diff = INT_MAX;
    ll one = a[0], two = a[1];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++){
        if(a[i+1] - a[i] < diff){
            diff = a[i+1] - a[i];
            one = a[i];
            two = a[i+1];
        }
    }
    bool first = false, second = false;
    vector<ll> res;
    for(int i = 0; i < n; i++){
        if(a[i] == one and first == false){
            first = true;
            continue;
        }
        if(a[i] == two and second == false){
            second = true;
            continue;
        }
        res.emplace_back(a[i]);
    }
    sort(res.begin(), res.end());
    cout << one << " ";
    for(int i = 0; i < (int)res.size(); i++){
        if(res[i] >= one){
            cout << res[i] << " ";
        }
    }
    for(int i = 0; i < (int)res.size(); i++){
        if(res[i] >= one){
            break;
        }
        cout << res[i] << " ";
    }
    cout << two;
    cout << "\n";
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
