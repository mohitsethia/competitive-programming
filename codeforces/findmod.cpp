#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int ask(int n){
    cout << "? " << n << endl;
    int x;
    cin >> x;
    return x;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n = 1e18+1;
        int d = ask(n);
        n -= d+1;
        int se = ask(n);
        cout << "! " << se+1 << endl;
    }
    return 0;
}
