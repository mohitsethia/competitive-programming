#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long
map<int, int> visited;
int ans = 0;
void dfs(int x, int& n){
    if(x > n) return;
    if(visited.find(x) != visited.end()) return;
    visited[x]++;
    ans++;
    dfs(x*10, n);
    dfs(x*10+1, n);
}
int32_t main(){
    int n;
    cin >> n;
    dfs(1, n);
    cout << ans << endl;
    return 0;
}
