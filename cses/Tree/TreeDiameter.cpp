#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+1;
vector<int> g[N];
int diameter[N];
int downPath[N];
void evaluate_downPaths(int src, int p){
    int bestChild = 0;
    bool leaf = true;
    for(auto child: g[src]){
        if(child != p){
            leaf = false;
            evaluate_downPaths(child, src);
            bestChild = max(bestChild, downPath[child]);
        }
    }
    if(leaf) downPath[src] = 0;
    else downPath[src] = 1 + bestChild;
}
void solve(int src, int p){
    int ans = 0;
    vector<int> ChildrenDownPath;
    for(auto child: g[src]){
        if(child != p){
            solve(child, src);
            ChildrenDownPath.emplace_back(downPath[child]);
            ans = max(ans, diameter[child]);
        }
    }
    int numOfChildren = ChildrenDownPath.size();
    sort(ChildrenDownPath.begin(), ChildrenDownPath.end());
    if(numOfChildren == 0){
        diameter[src] = 0;
    }
    else if(numOfChildren == 1){
        diameter[src] = 1 + ChildrenDownPath[numOfChildren-1];
    }
    else{
        diameter[src] = 2 + ChildrenDownPath[numOfChildren-1] + ChildrenDownPath[numOfChildren-2];
    }
    diameter[src] = max(diameter[src], ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    evaluate_downPaths(1, 0);
    solve(1, 0);
    cout << diameter[1];
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+1;
int n;
vector<int> g[N];
int lvl[N];
int farthestNode = 1;
int farthestDistance = 0;
void dfs(int z, int p){
    lvl[z] = lvl[p]+1;
    if(lvl[z] > farthestDistance){
        farthestDistance = lvl[z];
        farthestNode = z;
    }
    for(auto it: g[z]){
        if(it == p) continue;
        dfs(it, z);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    lvl[0] = -1;
    dfs(1, 0);
    int node = farthestNode;
    int dist = farthestDistance;
    lvl[0] = -1;
    farthestDistance = 0;
    dfs(node, 0);
    cout << farthestDistance << '\n';
    return 0;
}
*/
