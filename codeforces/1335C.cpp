#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> mp;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            mp[x]++;
        }
        int mn = (int)mp.size();
        int mx = 0;
        for(auto it: mp){
            mx = max(mx, it.second);
        }
        x = min(mn, mx);
        if(x == mn && x == mx) x--;
        cout << x << "\n";
    }
    return 0;
}
