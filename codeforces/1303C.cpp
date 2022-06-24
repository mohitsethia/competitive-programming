#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        vector<set<int> > g(26);
        for(int i = 0; i < n-1; i++){
            int a = s[i]-'a';
            int b = s[i+1]-'a';
            g[a].insert(b);
            g[b].insert(a);
        }
        bool ok = true;
        for(int i = 0; i < 26; i++){
            if(g[i].size() > 2){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << "NO\n";
            continue;
        }
        string ans = "";
        vector<bool> vis(26, false);
        function<void(int)> dfs = [&](int v){
            ans += ('a'+v);
            vis[v] = true;
            for(auto k : g[v]){
                if(!vis[k]){
                    dfs(k);
                }
            }
        };
        for(int i = 0; i < 26; i++){
            if(vis[i]) continue;
            if(g[i].size() == 0){
                ans += ('a' + i);
                vis[i] = true;
            }
            else if(g[i].size() == 1){
                dfs(i);
            }
        }
        if(ans.size() != 26){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << ans << "\n";
        }
    }
    return 0;
}
