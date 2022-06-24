#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>
using namespace std;
#define int long long
int32_t main(){
    int n, k;
    cin >> n >> k;
    int a[k];
    for(int i = 0; i < k; i++){
        a[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        a[i%k] += t;
    }
    int m = 0;
    for(int i = 0; i < k; i++){
        if(a[i] < a[m]){
            m = i;
        }
    }
    cout << m+1;
    return 0;
}
