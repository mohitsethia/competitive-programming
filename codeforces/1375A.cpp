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
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        for(int i = 0; i < n; i += 2) a[i] = -a[i];
            for(int i: a){
                cout << i << " ";
            }
            cout << "\n";
    }
    return 0;
}
