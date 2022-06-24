#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(),b.end());
    int cnt = 0;
    for(int i = 0 ; i < n; i++){
        if(a[i] != b[i]){
            cnt++;
            if(cnt > 2){
                break;
            }
        }
    }
    if(cnt > 2){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}

