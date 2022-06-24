#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    vector<int> b;
    for(int i = 0; i < n; i++){
        if(i != 0 && a[i] == a[i-1]){
            b.push_back(a[i]);
            continue;
        }
        cout << a[i] << " ";
    }
    for(int& i: b){
        cout << i << " ";
    }
    cout << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
