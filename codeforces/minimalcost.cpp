#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e3;
int a[maxn+5];
int solve(int n, int u, int v){
    for(int i = 1; i < n; i++){
        if(abs(a[i+1] -a[i]) >= 2){
            return 0;
        }
    }
    for(int i = 1; i < n; i++){
        if(abs(a[i+1] -a[i]) == 1){
            return min(u, v);
        }
    }
    return v+min(u, v);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, u, v;
        cin >> n >> u >> v;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int res = solve(n, u, v);
        cout << res << endl;
    }
    return 0;
}
