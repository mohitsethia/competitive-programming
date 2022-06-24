#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
#define pb push_back
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    int mp[n+1] {};
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        mp[p[i]] = i;
    }
    vector<pair<int, int> > ans;
    for(int i = 1; i <= n; i++){
        int diff = 2*abs(mp[i]-i);
        if(diff == 0) continue;
        else if(diff >= n){
            ans.pb({i, mp[i]});
        }
        else{
            if(2*mp[i]-1 >= n && 2*(n-i) >= n){
                ans.pb({1, mp[i]});
                ans.pb({i, n});
                ans.pb({1, n});
                ans.pb({i, n});
                ans.pb({1, mp[i]});
            }
            else if(2*(n-mp[i]) >= n && 2*(i-1) >= n){
                ans.pb({n, mp[i]});
                ans.pb({n, 1});
                ans.pb({i, 1});
                ans.pb({n, 1});
                ans.pb({n, mp[i]});
            }
            else if(2*(mp[i]-1) >= n && 2*(i-1) >= n){
                ans.pb({1, mp[i]});
                ans.pb({1, i});
                ans.pb({1, mp[i]});
            }
            else{
                ans.pb({n, mp[i]});
                ans.pb({n, i});
                ans.pb({n, mp[i]});
            }
        }
        mp[p[i]] = mp[i];
        swap(p[i], p[mp[i]]);
        mp[i] = i;
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}
