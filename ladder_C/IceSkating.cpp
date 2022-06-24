#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;
#define int long long

void dfs(vector<int>& x, vector<int>& y, int i, vector<int>& f, int& n){
    f[i] = 1;
    for(int j = 1; j <= n; j++){
        if(f[j] != 1 && (x[i] == x[j] || y[i] == y[j])){
            dfs(x, y, j, f, n);
        }
    }
}

int32_t main(){
    int n;
    cin >> n;
    vector<int> x(n+1), y(n+1), f(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(f[i] != 1){
            dfs(x, y, i, f, n);
            ans++;
        }
    }
    cout << ans-1 << endl;
    return 0;
}
