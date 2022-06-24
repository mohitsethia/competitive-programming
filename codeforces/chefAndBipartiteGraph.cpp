#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){   
        int n, m, d, D;
        cin >> n >> m >> d >> D;
        vector<vector<int> > A(n+1, vector<int>(n+1, 0)), deg(2, vector<int>(n+1, 0));
        int offset = 0, x = 1;
        while(m--){
            int y = x + offset;
            if(y > n){
                y -= n;
            }
            A[x][y] = 1;
            deg[0][x]++;
            deg[1][y]++;
            x++;
            if(x > n){
                x -= n;
                offset++;
            }
        }
        bool ok = true;
        for(int i = 1; i <= n; i++){
            ok &= (deg[0][i] >= d && deg[0][i] <= D);
            ok &= (deg[1][i] >= d && deg[1][i] <= D);
            if(!ok) break;
        }
        if(!ok){
            cout << "-1" << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[i][j]){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    return 0;
}
