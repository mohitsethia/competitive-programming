#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, vector<int> > mp;
        int x;
        for(int i = 1; i <= n; i++){
            cin >> x;
            mp[x].push_back(i);
        }
        int ans = 0;
        for(auto x: mp){
            int sz = x.second.size();
            int pre[sz];
            pre[sz-1] = n-x.second.back() + 1;
            for(int i = sz - 2; i >= 0; i--){
                pre[i] = pre[i+1] + (n-x.second[i] + 1);
            }
            for(int i = 0; i < sz-1; i++){
                ans += (x.second[i])*pre[i+1];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
