#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i-1]){
            cnt++;
        }
        else{
            break;
        }
    }
    if(cnt == n-1){
        cout << "0\n";
        return;
    }
    cout << a.size() - cnt - 1 << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
