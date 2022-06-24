#include<iostream>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n][m], maxx = INT_MIN, minn = INT_MAX;
        for(int i = 0; i < n; i++)[
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] > maxx){
                    maxx = a[i][j];
                }
                if(a[i][j] < minn){
                    minn = a[i][j];
                }
            }
        }
    }
    return 0;
}
