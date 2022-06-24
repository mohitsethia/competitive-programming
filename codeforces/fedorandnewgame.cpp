#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[m+1];
    for(int i = 0; i <= m; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int tmp = (a[m]^a[i]);
        int cool = 0;
        for(int j = 0; j < n; j++){
            if(tmp&(1<<j)){
                cool++;
            }
        }
        if(cool <= k){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
