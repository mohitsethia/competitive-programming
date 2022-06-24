#include<iostream>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n], p[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int mn = INT_MAX, id = -1;
        for(int i = 0; i < n; i++){
            if(a[i] <= n && a[a[i]] <= n){
                if(k % a[a[i]] == 0){
                    int cnt = k/a[a[i]];
                    if(cnt < mn){
                        mn = cnt;
                        id = i;
                    }
                }
            }
        }
        if(mn == INT_MAX){
            cout << "-1" << endl;
        }
        else{
            cout << id << endl;
        }
    }
    return 0;
}
