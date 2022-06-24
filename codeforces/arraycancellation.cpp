#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, curr = 0, x;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            curr = max(0ll, curr + x);
        }
        cout << curr << endl;
    }
    return 0;
}
