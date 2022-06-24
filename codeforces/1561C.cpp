#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int> > a(n);
    vector<pair<int, int> > v;
    vector<int> mx(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            a[i].push_back(x-j);
            mx[i] = max(mx[i], a[i].back());
        }
        v.push_back({mx[i], i});
    }
    sort(v.begin(), v.end());
    int l = 0, r = 1e6, ans = 1e6;
    while(l <= r){
        int mid = (l+r)/2;
        int val = mid;
        bool ok = true;
        for(auto i: v){
            if(i.first >= val){
                ok = false;
                break;
            }
            val += a[i.second].size();
        }
        if(ok){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
