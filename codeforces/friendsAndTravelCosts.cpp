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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > f(n);
    for(int i = 0; i < n; i++){
        cin >> f[i].first >> f[i].second;
    }
    int curr = k;
    k = 0;
    sort(f.begin(), f.end());
    for(int i = 0; i < n; i++){
        if(f[i].first <= curr){
            k = f[i].second;
            curr += k;
            k = 0;
        }
        else{
            break;
        }
    }
    cout << curr << endl;
    return 0;
}
