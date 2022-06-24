#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int freq[n+1];
    int mx = 0, c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        freq[a[i]]++;
        if(freq[a[i]] > mx){
            mx = freq[a[i]];
            c = a[i];
        }
    }
    mx /= 2;
    if(mx = 0
    return 0;
}
