#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int x, index = 0;
        for(int i = 1; i <= n; i++){
            cin >> x;
            if(x != i){
                index = i;
            }
        }
        double ans = 0;
        double rev = 1.0;
        double y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            if(x >= index){
                ans += (rev*y);
                rev *= (1.0-y);
            }
        }
        if(index == 0) ans = 1.0;
        cout << ans << endl;
    }
    return 0;
}
