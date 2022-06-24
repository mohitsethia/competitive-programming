#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
void solve(vector<int>& a, int l, int r, vector<int>& d, int currD){
    if(l > r){
        return;
    }
    if(l == r){
        d[l] = currD;
        return;
    }
    int m = l;
    for(int i = l+1; i <= r; i++){
        if(a[m] < a[i]){
            m = i;
        }
    }
    d[m] = currD;
    solve(a, l, m-1, d, currD+1);
    solve(a, m+1, r, d, currD+1);
}
int main(){
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
        vector<int> d(n);
        solve(a, 0, n-1, d, 0);
        for(int i = 0; i < n; i++){
            cout << d[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
