#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(b == 0){
            cout << "0" << endl;
        }
        else{
            if(a%b != 0){
                ll rem = a/b;
                ll ans = (rem+1)*b - a;
                cout << ans << endl;
            }
            else if(a%b == 0){
                cout << "0" << endl;   
            }
        }
    }
    return 0;
}
