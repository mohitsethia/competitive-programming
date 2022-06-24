#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int solve(int& n, vector<int> a){
    vector<int> v;
    int diff = a[1]-a[0];
    for(int i = 1; i < n; i++){
        
    }
    return max_cnt;
}
int32_t main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x: a){
            cin >> x;
        }
        int ans = solve(n, a);
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;   
}
