#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<int , int> mp;
    bool ok = true;
    while(n){
        mp[(n%m)]++;
        if(mp[n%m] > 1){
            ok = false;
            break;
        }
        n /= m;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
