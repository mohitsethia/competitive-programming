#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int r, g, b, w;
        cin >> r >> g >> b >> w;
        int cnt = 0;
        if(r%2 != 0){
            cnt++;
        }
        if(g%2 != 0){
            cnt++;
        }
        if(b%2 != 0){
            cnt++;
        }
        if(w%2 != 0){
            cnt++;
        }
        if(cnt == 0 || cnt == 4 || cnt == 1){
            cout << "YES" << endl;
            continue;
        }
        if(cnt == 3){
            if(r == 0 || g == 0 || b == 0){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
            continue;
        }
        if(cnt == 2){
            cout << "NO" << endl;
        }
    }
    return 0;
}
