#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n, x;
    cin >> n >> x;
    if(x == 1 || x%n == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
