#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int cnt = 1;
        n -= 2;
        while(n > x){
            n -= x;
            cnt++;
        }
        if(n > 0) cnt++;
        cout << cnt << "\n";
    }
    return 0;
}
