#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<map>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n);
        int sum = 0;
        map<int, int> mp;
        bool found = false;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(!found){
                mp[b[i]]++;
                if(mp[b[i]] == 2){
                    found = true;
                }
            }
        }
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
