#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int amp(int x){
    if(x < 0){
        return 0;
    }
    else{
        return x;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        unordered_map<char, int> mp;
        string s;
        cin >> s;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        for(int i = 0; i < q; i++){
            int c;
            cin >> c;
            int ans = 0;
            for(auto it : mp){
                ans += amp(it.second - c);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
