#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int mx = abs(a[n-1]-a[0])+abs(a[n-1]-a[1])+abs(a[1]-a[0]);
        cout << mx << endl;
    }
    return 0;
}
