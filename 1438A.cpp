#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 1;
        while(n--){
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}
