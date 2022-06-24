#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, b, p, flag = 1;
    cin >> t >> n >> b >> p;
    if(t == 0){
        flag = 0;
        return 0;
    }
    while(t--){
        vector<vector<int> > blocks(n+1);
        for(int lm = 0; lm < n*b; lm++){
            int x;
            cin >> x;
            if(x > 5){
                int mx = -1, idx = 1;
                for(int i = 1; i <= n; i++){
                    if(blocks[i].size() > mx && blocks[i].size() < b){
                        mx = blocks[i].size();
                        idx = i;
                    }
                }
                cout << idx << endl;
                blocks[idx].push_back(x);
            }
            else{
                for(int i = 1; i <= n; i++){
                    if(blocks[i].size() < b){
                        cout << i << endl;
                        blocks[i].push_back(x);
                        break;
                    }
                }
            }
        }
    }
    int y;
    if(flag)
        cin >> y;
    return 0;
}
