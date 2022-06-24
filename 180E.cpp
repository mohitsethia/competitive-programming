#include<iostream>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    set<pair<int, int> > s;
    for(int i = 1; i <= n; i++) s.insert({0, a[i]});
    map<int, int> f;
    int l = 1;
    int ans = 0;
    for(int r = 1; r <= n; r++){
        s.erase({f[a[r]], a[r]});
        f[a[r]]++;
        s.insert({f[a[r]], r});
        while(r-l+1-k > s.rbegin()->first){
            s.erase({f[a[l]], a[l]});
            f[a[l]]--;
            l++;
            s.insert({f[a[l]], a[l]});
        }
        ans = max(ans, s.rbegin()->first);
    }
    cout << ans << "\n";
    return 0;
}
