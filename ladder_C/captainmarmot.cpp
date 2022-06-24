#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
#define int long long
using namespace std;
struct node{
    int x, y;
};
node p[5][5], home[5];
int d[6];
int distance(node a, node b){
    return (int) (a.x - b.x)*(a.x - b.x) + (int)(a.y - b.y)*(a.y-b.y);
}
void solve(){
    int ans = INT_MAX;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    d[0] = distance(p[i][0], p[j][1]);
                    d[1] = distance(p[j][1], p[k][2]);
                    d[2] = distance(p[k][2], p[l][3]);
                    d[3] = distance(p[l][3], p[i][0]);
                    d[4] = distance(p[i][0], p[k][2]); //diagonal
                    d[5] = distance(p[j][1], p[l][3]); //diagonal
                    sort(d, d+6);
                    if(d[0] && d[0] == d[1] and d[1] == d[2] and d[2] == d[3] and 2*d[3] == d[4] and d[4] == d[5]){
                        ans = min(ans, i+j+k+l);
                    }
                }
            }
        }
    }
    if(ans == INT_MAX){
        cout << "-1\n";
    }
    else{
        cout << ans << endl;
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        //rotation of a point (a, y) around the point (a, b) = (a-(y-b), b+(x-a))
        for(int i = 0; i < 4; i++){
            int a, b, x, y;
            cin >> x >> y >> a >> b;
            p[0][i].x = x;
            p[0][i].y = y;
            home[i].x = a;
            home[i].y = b;
            p[1][i].x = a-(y-b);
            p[1][i].y = b+(x-a);
            x = p[1][i].x, y = p[1][i].y;
            p[2][i].x = a-(y-b);
            p[2][i].y = b+(x-a);
            x = p[2][i].x, y = p[2][i].y;
            p[3][i].x = a-(y-b);
            p[3][i].y = b+(x-a);
        }
        solve();
    }
    return 0;
}
