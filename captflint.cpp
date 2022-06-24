#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 30){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int ans = n-30;
            if(ans == 6 || ans == 10 || ans == 14){
                cout << "6 10 15 " << n-31 << endl;
                continue;
            }
            cout << "6 10 14 " << n-30 << endl;
        }
    }
    return 0;
}
