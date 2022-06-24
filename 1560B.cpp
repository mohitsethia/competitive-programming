#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int diff = max(a, b)-min(a, b);
        if(max(a, max(b, c)) > 2*diff){
            cout << "-1\n";
        }
        else{
            if(c <= diff){
                cout << c+diff << "\n";
            }
            else{
                cout << c-diff << "\n";
            }
        }
    }
    return 0;
}
