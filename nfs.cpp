#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int u, v, a, s;
        cin >> u >> v >> a >> s;
        if(u <= v){
            cout << "YES\n";
        }
        else{
            if((u*u - v*v) <= 2*a*s){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
