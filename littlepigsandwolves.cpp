#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    char grid[n+2][m+2];
    memset(grid, '.', sizeof(grid));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == 'W' && (grid[i-1][j] == 'P' || grid[i][j-1] == 'P' || grid[i+1][j] == 'P' || grid[i][j+1] == 'P')){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
