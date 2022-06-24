#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<climits>
#include<cstdio>
#define int long long
using namespace std;
void solve(){
    int n, q, m;
    cin >> n >> q >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[1000001] = {};
    vector<int> ans(m+1);
    map<pair<int, int>, int> mp;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(a[l] > m){
            continue;
        }
        else if(a[l] <= m && a[r] > m){
            b[a[l]]++;
            b[m+1]--;
            
        }
        else if(a[r] <= m){
            b[a[l]]++;
            b[m+1]--;
            mp[{a[l], a[r]}]++;
        }
    }
    for(auto x: mp){
        int k = x.first.first, p = x.first.second, l = x.second;
        b[p+k] -= l, b[p+2*k] += l;
        int c = p+2*k;
        while(c+p <= m){
            c += p;
            b[c] -= l, b[c+k] += l;
            c += k;
        }
    }
    for(int i = 1; i <= m; i++){
        b[i] += b[i-1];
    }
    int maxx = 0;
    for(int i = 0; i <= m; i++){
        maxx = max(b[i], maxx);
    }
    cout << maxx << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
