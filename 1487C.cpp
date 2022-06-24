#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(j-i < n/2 || (n%2 && j-i == n/2)){
                cout << "1 ";
            }
            else if(n%2 == 0 && j-i == n/2){
                cout << "0 ";
            }
            else{
                cout << "-1 ";
            }
        }
    }
    cout << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
