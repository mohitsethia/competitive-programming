#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<iomanip>
using namespace std;
void solve(){
    int n, m;
    while(cin >> n && n){
        cin >> m;
        int u, v;
        double c;
        vector<vector<double> > streets(105, vector<double>(105, 0));
        for(int i = 0; i < m; i++){
            cin >> u >> v >> c;
            streets[u][v] = streets[v][u] = c/100.0;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    streets[i][j] = max(streets[i][j], streets[i][k]*streets[k][j]);
                }
            }
        }
        cout << setprecision(6) << fixed << streets[1][n]*100 << " percent\n";
    }
}
int main(){
    solve();
    return 0;
}
