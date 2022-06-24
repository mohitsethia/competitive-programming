#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int check(vector<int>& a, vector<int>& b, int mid){
    int c = 0, n = a.size();
    for(int i = 0; i < n; i++){
        if(b[i] == 0){
            continue;
        }
        else{
            c += max(0LL, (a[i] - mid/b[i]));
        }
    }
    return c;
}
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int r = 0;
    for(int j = 0; j < n; j++){
        cin >> b[j];
        r = max(r, a[j]*b[j]);
    }
    int l = 0;
    while(l < r){
        int mid = l+(r-l)/2;
        int balloons = check(a, b, mid);
        if(balloons > m){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}
