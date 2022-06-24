#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a[7];
        for(int i = 0; i < 7; i++) cin >> a[i];
        cout << a[0] << " " << a[1] << " " << a[6]-a[0]-a[1] << "\n";
    }
    return 0;
}
