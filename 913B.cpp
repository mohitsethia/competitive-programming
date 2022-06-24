#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> mp[n+1];
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        mp[p].push_back(i);
    }
    for(int i = 1; i <= n; i++){
        if(mp[i].size()){
            int cnt = 0;
            for(int j = 0; j < (int)mp[i].size(); j++){
                if(mp[mp[i][j]].size() == 0) cnt++;
            }
            if(cnt < 3){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
