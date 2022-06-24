#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int solve(vector<int>& a, int m){
    int curr = 0, mx = 0;
    for(int i = 0; i < m; i++){
        if(a[i] == 0) curr = 0;
        else curr++;
        mx = max(mx, curr);
    }
    return mx;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > a(n, vector<int>(m));
    int mx[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
        mx[i] = solve(a[i], m);
    }
    int i, j;
    while(q--){
        cin >> i >> j;
        i--, j--;
        a[i][j] = !a[i][j];
        mx[i] = solve(a[i], m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, mx[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
