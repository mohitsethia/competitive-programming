#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(b < a){
            cout << a-b << "\n";
            continue;
        }
        int s = b-a;
        // cout << s << " ";
        cout << (s+1)/2 + s%2 << "\n";
    }
    return 0;
}
