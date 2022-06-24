#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int n, m, x, cnt = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    cout << n-i << endl;
    return 0;
}
