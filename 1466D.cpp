#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n+1);
        vector<int> deg(n+1);
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            deg[u]++, deg[v]++;
        }
        int res = 0;
        vector<int> col;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j < deg[i]; j++){
                col.emplace_back(w[i]);
            }
            res += w[i];
        }
        sort(col.rbegin(), col.rend());
        cout << res << " ";
        for(int &v: col){
            res += v;
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}
