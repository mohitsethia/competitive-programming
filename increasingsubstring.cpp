#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 1;
    cout << cnt << " ";
    for(int i = 1; i < n; i++){
        if(s[i] > s[i-1]){
            cout << ++cnt << " ";
        }
        else{
            cnt = 1;
            cout << cnt << " ";
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
