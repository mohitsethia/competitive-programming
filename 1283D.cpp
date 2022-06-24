#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x;
    map<int, bool> vis;
    queue<pair<int, int> > q;
    for(int i = 0; i < n; i++){
        cin >> x;
        vis[x] = true;
        q.push({1, x-1});
        q.push({1, x+1});
    }
    vector<int> ans;
    int sum = 0;
    while(m && !q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        if(!vis.count(temp.second)){
            m--;
            sum += temp.first;
            ans.emplace_back(temp.second);
            vis[temp.second] = 1;
            if(!vis.count(temp.second+1)){
                q.push({temp.first+1, temp.second+1});
            }
            if(!vis.count(temp.second-1)){
                q.push({temp.first+1, temp.second-1});
            }
        }
    }
    cout << sum << "\n";
    for(auto it: ans){
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}
