#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        map<int, vector<int> > idv;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            idv[a[i]].push_back(i);
        }
        string ans = "NO";
        for(auto el : idv){
            if(el.second.size() >= 3){
                ans = "YES";
                break;
            }
            if(el.second.size() == 2 and el.second[0] != el.second[1] - 1){
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
