#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int b[101][101];
        multiset<pair<int, int> > mst;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                b[i][j] = -1;
                mst.insert({x, i});
            }
        }
        for(int i = 0; i < m; i++){ 
            auto itr = mst.begin();
            b[itr->second][i] = itr->first;
            mst.erase(itr);
        }
        while(!mst.empty()){
            auto itr = mst.begin();
            int in = 0;
            while(b[itr->second][in] != -1){
                in++;
            }
            b[itr->second][in] = itr->first;
            mst.erase(itr);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
