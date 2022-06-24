#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;
#define endl '\n'
struct bot{
    int x, d;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<bot> a(n);
        vector<int> pos(n);
        iota(pos.begin(), pos.end(), 0);
        for(int i = 0; i < n; i++){
            cin >> a[i].x;
        }
        for(int i = 0; i < n; i++){
            char c;
            cin >> c;
            if(c == 'L'){
                a[i].d = -1;
            }
            else{
                a[i].d = 1;
            }
        }
        sort(pos.begin(), pos.end(), [&a](int x, int y){
            return a[x].x < a[y].x;
        });
        vector<int> ans(n, -1);
        vector<vector<int> > par(2);
        for(int i: pos){
            int p = a[i].x % 2;
            if(a[i].d == -1){
                if(par[p].empty()){
                    par[p].push_back(i);
                }
                else{
                    int j = par[p].back();
                    par[p].pop_back();
                    ans[i] = ans[j] = (a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x))/2;
                }
            }
            else{
                par[p].push_back(i);
            }
        }
        for(int p = 0; p < 2; p++){
            while((int)par[p].size() > 1){
                int i = par[p].back();
                par[p].pop_back();
                int j = par[p].back();
                par[p].pop_back();
                ans[i] = ans[j] = (2*m - a[i].x - (a[j].d == 1 ? a[j].x : -a[j].x))/2;
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        puts("");
    }
    return 0;
}
