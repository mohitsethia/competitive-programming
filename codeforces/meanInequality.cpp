#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0, j = 2*n-1;
        while(i < j){
            cout << a[i] << " " << a[j] << " ";
            i++, j--;
        }
        if(i == j && n%2){
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}
