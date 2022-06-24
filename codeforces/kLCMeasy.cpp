/*


 _      _     _________  |-|   |-|  _________    _________
||\    /||    | _____ |  | |   | |  |___ ___|    |___ ___|
|| \  / ||    | |   | |  | ----- |     | |          | |
||  \/  ||    | |   | |  | ----- |     | |          | |
||      ||    | |___| |  | |   | |     | |          | |
||      ||    |_______|  |_|   |_|  ___| |___       | |
                                    |_______|       |_|
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    if(n%3 == 0){
        cout << n/3 << " " << n/3 << " " << n/3 << "\n";
        return;
    }
    if((n/2)+(n/2) == n){
        if((n/2)%2 == 0){
            cout << n/2 << " " << n/4 << " " << n/4 << "\n";
        }
        else{
            cout << n/2-1 << " " << n/2-1 << " " << "2\n";
        }
    }
    else{
        cout << n/2 << " " << n/2 << " " << "1\n";
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
