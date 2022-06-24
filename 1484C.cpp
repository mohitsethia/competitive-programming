#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > f(m);
        for(int i = 0; i < m; i++){
            int k;
            cin >> k;
            f[i] = vector<int>(k);
            for(int j = 0; j < k; j++){
                cin >> f[i][j];
            }
        }
        vector<int> cnt(m+1), ans(m, -1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < f[i].size(); j++){
                if(cnt[f[i][j]] > (m+1)/2){
                    continue;
                }
                else{
                    cnt[f[i][j]]++;
                    ans[i] = f[i][j];
                }
            }
        }
    return 0;
}
