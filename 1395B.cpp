#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, sx, sy;
    scanf("%lld%lld%lld%lld", &n, &m, &sx, &sy);
    printf("%lld %lld\n", sx, sy);
    vector<vector<ll> > vis(n+1, vector<ll>(m+1, 0));
    vis[sx][sy] = 1;
    if((sy == 1 && sx == 1) || vis[1][sy]){
    }
    else{
        printf("1 %lld\n", sy);
        vis[1][sy] = 1;
    }
    for(ll i = 1; i <= n; i++){
        if(i&1){
            for(ll j = 1; j <= m; j++){
                if(!vis[i][j]){
                    vis[i][j] = 1;
                    printf("%lld %lld\n", i, j);
                }
            }
        }
        else{
            for(ll j = m; j >= 1; j--){
                if(!vis[i][j]){
                    vis[i][j] = 1;
                    printf("%lld %lld\n", i, j);
                }
            }
        }
    }
    return 0;
}
