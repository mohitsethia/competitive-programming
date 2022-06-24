#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 2e5+5;
vector<int> g[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        vector<int> color(n, -1);
        queue<int> q;
        color[0] = 1;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            --x;
            q.push(x);
            color[x] = 0;
        }
        q.push(0);
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: g[u]){
                if(color[v] == -1){
                    color[v] = color[u];
                    q.push(v);
                }
            }
        }
        bool found = false;
        for(int i = 1; i < n; i++){
            if(g[i].size() == 1 && color[i] == 1){
                found = true;
                break;
            }
        }
        if(found){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
