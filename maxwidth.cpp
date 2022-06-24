#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int f[m], g[m];
    int i = 0, j = 0;
    while(i < n){
        if(s[i] == t[j]){
            f[j] = i;
            j++;
        }
        i++;
    }
    i = n-1; j = m-1;
    while(i >= 0){
        if(s[i] == t[j]){
            g[j] = i;
            j--;
        }
        i--;
    }
    int ans = 0;
    for(int i = 1; i < m; i++){
        ans = max(ans, g[i] - f[i-1]);
    }
    cout << ans << endl;
    return 0;
}
