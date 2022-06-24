#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = (1 << 13);

vector<int> g[N];
int ans[N], r[N];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ans[0] = 1;
    for(int i = 0; i < N; i++){
        g[i].push_back(0);
        r[i] = N;
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(auto k: g[x]){
            int Xor = (k^x);
            ans[Xor] = 1;
            while(r[Xor] > x){
                r[Xor]--;
                if(r[Xor] != x){
                    g[r[Xor]].push_back(Xor);
                }
            }
        }
        g[x] = {};
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        res += ans[i];
    }
    cout << res << "\n";
    for(int i = 0; i < N; i++){
        if(ans[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}
