#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int prev;
    bool ok = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!i){
            prev = a[i];
        }
        else{
            if(prev != a[i]){
                ok = false;
            }
        }
    }
    if(ok){
        cout << "1\n";
        for(int i = 1; i <= n; i++){
            cout << 1 << " \n"[i == n];
        }
        return;
    }
    if(n%2 == 0){
        prev = 0;
        cout << "2\n";
        for(int i = 1; i <= n; i++){
            cout << prev+1 << " \n"[i == n];
            prev ^= 1;
        }
        return;
    }
    for(int j = 0; j < n; j++){
        if(a[j] == a[(j+1)%n]){
            vector<int> ans(n);
            prev = 0;
            for(int i = j+1; i < n; i++){
                ans[i] = prev+1;
                prev ^= 1;
            }
            prev = 0;
            for(int i = j; i >= 0; i--){
                ans[i] = prev+1;
                prev ^= 1;
            }
            cout << "2\n";
            for(int i = 0; i < n; i++){
                cout << ans[i] << " \n"[i == n-1];
            }
            return;
        }
    }
    prev = 0;
    cout << "3\n";
    for(int i = 0; i < n-1; i++){
        cout << prev+1 << " ";
        prev ^= 1;
    }
    cout << "3\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
