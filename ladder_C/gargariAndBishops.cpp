#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;
#define int long long
int n;
vector<vector<int> > mat(2005, vector<int>(2005));
vector<int> dp1(10000, 0), dp2(10000, 0);
/*
int value(int i, int j){
    int x = i, y = j;
    int ans = 0;
    while(x <= n && y <= n) ans += mat[x++][y++];
    x = i-1, y = j-1;
    while(x > 0 && y > 0) ans += mat[x--][y--];
    x = i-1, y = j+1;
    while(x > 0 && y <= n) ans += mat[x--][y++];
    x = i+1, y = j-1;
    while(x <= n && y > 0) ans += mat[x++][y--];
    return ans;
}
void solve(){
    int odd_max = 0, even_max = 0, x1, x2, y1, y2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int val = value(i, j);
            if((i+j)%2 == 0){
                if(even_max < val){
                    x1 = i, y1 = j;
                    even_max = val;
                }
            }
            else{
                if(odd_max < val){
                    x2 = i, y2 = j;
                    odd_max = val;
                }
            }
        }
    }
    cout << even_max+odd_max << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
*/
void solve(){
    int mx1 = -1, mx2 = -1;
    pair<int, int> c1, c2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if((i+j)%2){
                if(dp1[i+j]+dp2[i-j+2000]-mat[i][j] > mx1){
                    mx1 = dp1[i+j]+dp2[i-j+2000]-mat[i][j];
                    c1 = {i, j};
                }
            }
            else{
                if(dp1[i+j]+dp2[i-j+2000]-mat[i][j] > mx2){
                    mx2 = dp1[i+j]+dp2[i-j+2000]-mat[i][j];
                    c2 = {i, j};
                }
            }
        }
    }
    cout << mx1+mx2 << endl;
    cout << c1.first << " " << c1.second << " " << c2.first << " " << c2.second << endl;
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
            dp1[i+j] += mat[i][j];
            dp2[i-j+2000] += mat[i][j];
        }
    }
    solve();
    return 0;
}
