#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        bool mat[102][102] = {false};
        mat[x][y] = true;
        cout << x << " " << y << endl;
        if(x != 1){
            mat[1][y] = true;
            cout << 1 << " " << y << endl;
        }
        else if(y != 1){
            mat[x][1] = true;
            cout << x << " " << 1 << endl;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!mat[i][j]){
                    cout << i << " " << j << endl;
                }
            }
        }
    return 0;
}
