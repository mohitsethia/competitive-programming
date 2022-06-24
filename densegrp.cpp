#pragma GCC optimize("O3")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<queue>

using namespace std;
#define int long long

bool checkRange(std::vector<int>& q1, std::vector<int>& q2, int a, int b){
    for(int i = 0; i < q1.size(); i++){
        if(q1[i] <= b && q2[i] >= a){
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m, x, y, flag = 0;
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    //cin >> n >> m >> x >> y;
    std::vector<int> a(n), b(n), c(n), d(n), q1, q2;
    for(int i = 0; i < m; i++){
        scanf("%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i]);
        //cin >> a >> b >> c >> d;
        if(x >= a[i] && x <= b[i] && y >= c[i] && y <= d[i]){
            flag = 1;
        }
    }
    if(x == y){
        printf("0\n");
        return;
    }
    if(flag){
        printf("1\n");
        return;
    }
    q1.push_back(x);
    q2.push_back(x);
    vector<bool> visited(m, false);
    int pathLength = 0;
    while(q1.size()){
        std::vector<int> v1, v2;
        for(int i = 0; i < m; i++){
            if(!visited[i] && checkRange(q1, q2, a[i], b[i])){
                if(y >= c[i] && y <= d[i]){
                    printf("%lld\n", pathLength+1);
                    return;
                }
                v1.push_back(c[i]);
                v2.push_back(d[i]);
                visited[i] = true;
            }
        }
        q1 = v1;
        q2 = v2;
        pathLength++;
    }
    printf("-1\n");
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}
