#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 1e5+5;
vector<int> mp[MAXN];
vector<int> ans;
vector<int> arr1, arr2;
void dfs(int curr, int parent, int layer, int odd, int even){
    if(((layer%2) && (odd%2)) || ((layer%2 == 0) && (even%2))){
        arr1[curr-1] ^= 1;
    }
    if(arr1[curr-1] != arr2[curr-1]){
        ans.push_back(curr);
        if(layer%2) odd ^= 1;
        else even ^= 1;
    }
    for(int i = 0; i < mp[curr].size(); i++){
        int v = mp[curr][i];
        if(v == parent) continue;
        dfs(v, curr, layer+1, odd, even);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i = 0 ;i < n; i++){
        int a;
        cin >> a;
        arr1.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr2.push_back(a);
    }
    dfs(1, -1, 1, 0, 0);
    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
