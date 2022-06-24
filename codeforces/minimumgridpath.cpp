#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = LLONG_MAX, precompute = 0, c;
        cin >> n;
        priority_queue<int, vector<int>, greater<int> > odd, even;
        for(int i = 0; i < n; i++){
            cin >> c;
            i%2 ? odd.push(c) : even.push(c);
            precompute += c;
            if(i){
                ans = min(ans, precompute + (n- (int)even.size())*even.top() + (n-(int)odd.size())*odd.top());
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
