#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int32_t main(){
    int n, m;
    cin >> n >> m;
    if(m == 0 || n == 0){
        cout << "YES" << endl;
        return 0;
    }
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0] == 1 || a[m-1] == n){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < m-2; i++){        
        if(a[i]+2 == a[i+2] && a[i]+1 == a[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
