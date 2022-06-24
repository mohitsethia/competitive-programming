#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define int long long
using namespace std;
void solve(){
    int p, a, b, c;
    cin >> p >> a >> b >> c;
    int x = a, y = b, z = c;
    if(a < p){
        if(p%a){
            a = a*((p/a)+1);
        }
        else{
            a = a*(p/a);
        }
    }
    if(b < p){
        if(p%b){
            b = b*((p/b)+1);
        }
        else{
            b = b*(p/b);
        }
    }
    if(c < p){
        if(p%c){
            c = c*((p/c)+1);
        }
        else{
            c = c*(p/c);
        }
    }
    int mn = min(a, min(b, c));
    cout << mn - p << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
