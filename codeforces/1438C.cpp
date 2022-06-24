#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > grid(n, vector<int> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ;j++){
                cin >> grid[i][j];
                if((i+j)%2 == 0){
                    if(grid[i][j]%2 == 0) grid[i][j]++;
                }
                else{
                    if(grid[i][j]%2) grid[i][j]++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j] << " \n"[j == m-1];
            }
        }
    }
    return 0;
}
