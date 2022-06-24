#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

// vector<vector<int> > convertToAdjMatrix(map<int, vector<int> > &graph){
// }

int tsp(vector<vector<int> > &dist, int n, int mask, int pos, vector<vector<int> > &dp, int start){
    if(mask == ((1 << n) - 1)) return dist[pos][start];
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;
    for(int city = 0; city < n; city++){
        if((mask&(1 << city)) == 0){
            ans = min(ans, dist[pos][city] + tsp(dist, n, mask|(1<<city), city, dp, start));
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> > dist(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> dist[i][j];
    }
    vector<vector<int> > dp;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        dp = vector<vector<int> >((1<<n), vector<int>(n, -1));
        int res = tsp(dist, n, (1 << i), i, dp, i);
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}
