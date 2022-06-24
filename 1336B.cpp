#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int m = 3;
        vector<vector<int>> w(m);
        vector<int> sz(m);
        for(int i = 0; i < m; i++) cin >> sz[i];
        for(int i = 0; i < m; i++){
            w[i].resize(sz[i]);
            for(int &j: w[i]){
                cin >> j;
            }
            sort(w[i].begin(), w[i].end());
        }
        auto calc = [&](int x, int y, int z){
            int t1 = (x-y), t2 = (y-z), t3 = (z-x);
            return t1*t1 + t2*t2 + t3*t3;
        };
        vector<int> ids = {0, 1, 2};
        int best = 9e18+69;
        do{
            vector<int> p(3);
            for(p[0] = 0; p[0] < sz[ids[0]]; p[0]++){
                while(p[1] < sz[ids[1]]-1 && w[ids[0]][p[0]] >= w[ids[1]][p[1]+1]) ++p[1];
                while(p[2] < sz[ids[2]]-1 && w[ids[0]][p[0]] > w[ids[2]][p[2]]) ++p[2];
                best = min(best, calc(w[ids[0]][p[0]], w[ids[1]][p[1]], w[ids[2]][p[2]]));
            }
        }while(next_permutation(ids.begin(), ids.end()));
        cout << best << "\n";
    }
    return 0;
}
