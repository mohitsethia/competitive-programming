#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        if(d <= n){
            cout << "YES\n";
        }
        else{
            bool ok = false;
            for(int i = 1; i <= min(d, 100000ll); i++){
                if(i + (d+i)/(i+1) <= n){
                    ok = true;
                    break;
                }
            }
            if(ok){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
