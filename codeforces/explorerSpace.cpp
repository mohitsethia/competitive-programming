#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(k%2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << "-1" << " \n"[j == m-1];
            }
        }
        return 0;
    }
    long long edge_right[n][m], edge_down[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            cin >> edge_right[i][j];
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            cin >> edge_down[i][j];
        }
    }
    vector<vector<vector<long long> > > dp(n, vector<vector<long long> >(m, vector<long long>(k, 0)));
    for(int i = 1; i <= k/2; i++){
        for(int a = 0; a < n; a++){
            for(int b = 0; b < m; b++){
                long long temp = INT_MAX;
                if(a > 0){
                    temp = min(temp, edge_down[a-1][b]+dp[a-1][b][i-1]);
                }
                if(a+1 < n){
                    temp = min(temp, edge_down[a][b]+dp[a+1][b][i-1]);
                }
                if(b > 0){
                    temp = min(temp, edge_right[a][b-1]+dp[a][b-1][i-1]);
                }
                if(b+1 < m){
                    temp = min(temp, edge_right[a][b]+dp[a][b+1][i-1]);
                }
                dp[a][b][i] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dp[i][j][k/2]*2 << " \n"[j == m-1];
        }
    }
    return 0;
}
