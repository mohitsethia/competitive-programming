#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll r, b, d;
        cin >> r >> b >> d;
        if(min(r, b)*(d+1) < max(r, b)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
