#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x;
        cin >> a >> b >> x;
        if(a == x || b == x || abs(a-b) == x || abs(a-abs(a-b)) == x || abs(b-abs(a-b)) == x){
            cout << "YES\n";
        }else{
            if(a > b) swap(a, b);
            if(x > b){
                cout << "NO\n";
                continue;
            }
            bool found = false;
            while(a){
                if(x <= b && x%a == b%a){
                    found = true;
                    break;
                }
                b %= a;
                swap(a, b);
            }
            if(found) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
