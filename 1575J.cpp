#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];
    while(k--){
        int col;
        cin >> col;
        int row = 1;
        while(row <= n){
            if(grid[row][col] == 1){
                grid[row][col] = 2;
                col++;
            }
            else if(grid[row][col] == 2){
                row++;
            }
            else{
                grid[row][col] = 2;
                col--;
            }
        }
        cout << col << " ";
    }
    return 0;
}
