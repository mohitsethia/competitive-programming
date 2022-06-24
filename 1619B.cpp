#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        map<int, int> mp;
        int n;
        cin >> n;
        for(int i = 1; i*i <= n; i++){
            mp[i*i] = 1;
        }
        for(int i = 1; i*i*i <= n; i++){
            mp[i*i*i] = 1;
        }
        cout << mp.size() << "\n";
    }
    return 0;
}
