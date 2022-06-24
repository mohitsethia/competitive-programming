#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i-k < 0){
            sum += a[i];
        }
        else{
            cout << sum << "\n";
            pq.push(sum);
            sum -= a[i-k-1];
            sum += a[i];
            if(i == n-1){
                pq.push(sum);
            }
        }
    }
    while(!pq.empty()){
//        cout << pq.top() << "\n";
        pq.pop();
    }   
    int ans = 0;
    while(!pq.empty()){
//        cout << ans << "\n";
        if(pq.top() == 1){
            pq.pop();
            ans++;
        }
        else{
            ans += pq.top();
            int sum = pq.top();
            pq.pop();
            pq.push(--sum);
        }
    }
    cout << ans << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
