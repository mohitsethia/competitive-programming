#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(a[n-1] == 1 && a[0] == n){
            cout << 3 << endl;
            continue;
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        if(a == b){
            cout << "0\n";
        }
        else if(a[0] == 1 || a[n-1] == n){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}
