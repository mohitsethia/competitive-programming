#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int best = 0;
    for(int i = 0; i < n; i++){
        int o = s[i%(best+1)];
        int l = s[i];
        if(l > o) break;
        if(l < o) best = i;
    }
    for(int i = 0; i < k; i++){
        cout << s[i%(best+1)];
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
