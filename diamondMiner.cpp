#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<iomanip>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> miner, diamond;
        for(int i = 0; i < 2*n; i++){
            int x, y;
            cin >> x >> y;
            if(x == 0){
                y = y < 0 ? -1*y : y;
                miner.push_back(y);
            }
            else{
                x = x < 0 ? -1*x : x;
                diamond.push_back(x);
            }
        }
        sort(miner.begin(), miner.end());
        sort(diamond.begin(), diamond.end());
        double dist = 0;
        for(int i = 0; i < n; i++){
            dist += sqrt(miner[i]*miner[i] + diamond[i]*diamond[i]);
        }
        cout << fixed << setprecision(15) << dist << endl;
    }
    return 0;
}
