#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> res(n+1, 1);
        n = unique(a.begin(), a.end()) - a.begin();
        a.resize(n);
        for(int i = 0; i < n; i++){
            res[a[i]]++;
        }
        res[a[0]]--;
        res[a[n-1]]--;
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            ans = min(ans, res[a[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}
