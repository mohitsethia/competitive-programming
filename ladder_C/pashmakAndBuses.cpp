#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    int temp = 1;
    bool check = false;
    for(int i = 0; i < d; i++){
        temp *= k;
        if(temp >= n){
            check = true;
            break;
        }
    }
    if(!check){
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(d, 0));
    for(int i = 1; i < n; i++){
        for(int j = 0 ; j < d; j++){
            ans[i][j] = ans[i-1][j];
        }
        for(int j = d-1; j >= 0; j--){
            ans[i][j] = (ans[i][j]+1)%k;
            if(ans[i][j]) break;
        }
    }
    for(int i = 0; i < d; i++, cout << endl){
        for(int j = 0; j < n; j++){
            cout << ans[j][i] + 1 << ' ';
        }
    }
    return 0;
}
