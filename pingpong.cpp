#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define int long long
using namespace std;

int a[101] = {0}, b[101] = {0}, f[101] = {0}, n = 0;
void dfs(int x){
    f[x] = 1;
    for(int i = 1; i <= n; i++){
        if(f[i]){
            continue;
        }
        if(a[x] > a[i] && a[x] < b[i]){
            dfs(i);
        }
        if(b[x] > a[i] && b[x] < b[i]){
            dfs(i);
        }
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, m;
        cin >> m;
        if(m == 1){
            n++;
            cin >> x >> y;
            a[n] = x;
            b[n] = y;
        }
        else{
            cin >> x >> y;
            memset(f, 0, sizeof(f));
            dfs(x);
            if(f[y]){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
