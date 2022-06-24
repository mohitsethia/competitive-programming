#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
using ll = long long;
ll R, G, B;
ll ans = 0;
ll dp[205][205][205];
ll solve(vector<ll> &red, vector<ll> &green, vector<ll> &blue, int i, int j, int k){
    if((i >= R && j >= G) || (k >= B && j >= G) || (i >= R && k >= B)){
        return 0;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll op = 0;
    if(i < R && k < B)
        op = max(op, red[i]*blue[k] + solve(red, green, blue, i+1, j, k+1));
    if(i < R && j < G)
        op = max(op, red[i]*green[j] + solve(red, green, blue, i+1, j+1, k));
    if(j < G && k < B)
        op = max(op, green[j]*blue[k] + solve(red, green, blue, i, j+1, k+1));
    ans = max(ans, op);
    return dp[i][j][k] = op;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> G >> B;
    vector<ll> red(R), green(G), blue(B);
    memset(dp , -1, sizeof(dp));
    for(ll i = 0; i < R; i++)
        cin >> red[i];
    for(ll i = 0; i < G; i++)
        cin >> green[i];
    for(ll i = 0; i < B; i++)
        cin >> blue[i];
    sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());
    sort(blue.rbegin(), blue.rend());
    ll ans = solve(red, green, blue, 0, 0, 0);
    cout << ans << "\n";
    return 0;
}
