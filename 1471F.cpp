#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> edges[n+1];
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        vector<int> color(n+1, -1);
        queue<int> q;
        q.push(1);
        color[1] = 1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it: edges[temp]){
                if(color[it] == -1){
                    if(color[temp] == 0) color[it] = 1;
                    else color[it] = 0;
                    q.push(it);
                }
                else
                    if(color[temp] == 1) color[it] = 0;
            }
        }
        vector<int> colored;
        bool bad = false;
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                bad = true;
                break;
            }
            if(color[i] == 1) colored.push_back(i);
        }
        if(bad) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << colored.size() << "\n";
            for(auto it: colored){
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
