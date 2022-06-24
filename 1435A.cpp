#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n/2; i++){
            cout << a[n-i-1]*-1 << " ";
        }
        for(int i = n/2; i < n; i++){
            cout << a[n-i-1] << " ";
        }
        cout << "\n";
    }
    return 0;
}
