#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > ans;
        if(n < 10){
            int x = n-1;
            while(x > 2){
                ans.push_back({x, n});
                x--;
            }
            x = n;
            while(n > 1){
                ans.push_back({x, 2});
                n = (n+1)/2;
            }
        }
        else{
            int v = cbrt(n);
            v++;
            for(int x = 3; x < n; x++){
                if(x == v) continue;
                ans.push_back({x, n});
            }
            ans.push_back({n, v});
            ans.push_back({n, v});
            ans.push_back({n, v});
            int x = v;
            while(x > 1){
                ans.push_back({v, 2});
                x = (x+1)/2;
            }
        }
        cout << ans.size() << "\n";
        for(pair<int, int> i: ans){
            cout << i.first << " " << i.second << "\n";
        }
    }
    return 0;
}
