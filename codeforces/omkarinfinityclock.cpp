#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        int r = k%2;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
            cout << mx << " ";
        }
        for(int i = 0; i < n; i++){
            if(r){
                cout << (mx-a[i]) <<  " ";
            }
            else{
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
