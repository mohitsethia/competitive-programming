#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), pre(n), suf(n);
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0){
            if(a[i] > a[i-1]){
                pre[i] = pre[i-1]+1;
                maxx = max(maxx, pre[i]);
            }
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(a[i] > a[i+1]){
            suf[i] = suf[i+1]+1;
            maxx = max(maxx, suf[i]);
        }
    }
    int peaks = 0;
    for(int i = 0; i < n; i++){
        if(pre[i] == maxx) peaks++;
        if(suf[i] == maxx) peaks++;
    }
    int flag = 1;
    if(peaks > 2){
        flag = 0;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(pre[i] == maxx && suf[i] == maxx && maxx%2 == 0){
            ans++;
        }
    }
    cout << ((!flag) ? 0 : ans) << endl;
    return 0;
}
