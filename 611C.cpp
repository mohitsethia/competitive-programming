#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char> > grid(h+1, vector<char>(w+1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int> > horizontal_dp(h+1, vector<int>(w+1));
    vector<vector<int> > vertical_dp(h+1, vector<int>(w+1));
    int ans = 0;
    for(int i = 1; i <= h; i++){
        ans = 0;
        for(int j = 2; j <= w; j++){
            if(grid[i][j] == '.' && grid[i][j-1] == '.'){
                ans++;
            }
            horizontal_dp[i][j] = ans;
        }
    }
    for(int j = 1; j <= w; j++){
        ans = 0;
        for(int i = 2; i <= h; i++){
            if(grid[i][j] == '.' && grid[i-1][j] == '.'){
                ans++;
            }
            vertical_dp[i][j] = ans;
        }
    }
    int q;
    int r1, c1, r2, c2;
    cin >> q;
    while(q--){
        ans = 0;
        cin >> r1 >> c1 >> r2 >> c2;
        for(int i = r1; i <= r2; i++){
            ans += horizontal_dp[i][c2] - horizontal_dp[i][c1];
        }
        for(int i = c1; i <= c2; i++){
            ans += vertical_dp[r2][i] - vertical_dp[r1][i];
        }
        cout << ans << "\n";
    }
    return 0;
}
