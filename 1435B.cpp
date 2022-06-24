#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> row(n*m+1), col(n*m+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                row[x] = j;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x;
                cin >> x;
                col[x] = j;
            }
        }
        vector<vector<int> > grid(n, vector<int>(m));
        for(int i = 1; i <= n*m; i++){
            grid[col[i]][row[i]] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }

    }
    return 0;
}
