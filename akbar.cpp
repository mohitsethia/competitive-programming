#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
#define int long long
void clear(queue<int> &q){
    queue<int> empty;   
    swap(q, empty);
}
bool solve(){
    int n, r, m, x, y, k, s;
    cin >> n >> r >> m;
    map<int, vector<int> > mp;
    for(int i = 0; i < r; i++){
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    vector<bool> visited(n+1);
    bool flag = true;
    for(int i = 0; i < m; i++){
        cin >> k >> s;
        if(visited[k]){
            flag = false;
            continue;
        }
        if(!flag){
            continue;
        }
        if(s == 0){
            visited[k] = true;
            continue;
        }
        vector<bool> check(1000010, false);
        queue<int> q;
        q.push(k);
        while(!q.empty()){
            int sz = q.size();
            for(int j = 0; j < sz; j++){
                int u = q.front();
                q.pop();
                if(!visited[u]){
                    visited[u] = true;
                    check[u] = true;
                    for(auto city: mp[u]){
                        if(city != k && !check[city] && visited[city]){
                            flag = false;
                            clear(q);
                            j = sz;
                            break;
                        }
                        if(!visited[city]){
                            q.push(city);
                        }
                    }
                }
                else if(u != k && !check[u] && visited[u]){
                    flag = false;
                    clear(q);
                    break;
                }
            }
            if(s == 0){
                break;
            }
            s--;
        }
    }
    if(!flag){
        return false;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}

