#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n+1, vector<int>(m+1));
    int curr = 0;
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
        curr ^= a[i][1];
        ans[i] = 1;
    }
    if(curr == 0){
        bool done = false;
        for(int i = 1; i <= n; i++){
            for(int j = 2; j <= m; j++){
                if(a[i][j] != a[i][1]){
                    done = true;
                    ans[i] = j;
                    break;
                }
            }
            if(done) break;
        }
        if(!done){
            cout << "NIE\n";
            return 0;
        }
    }
    cout << "TAK\n";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
