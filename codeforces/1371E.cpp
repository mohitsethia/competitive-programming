#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0;
    for(int i = 0; i < n; i++){
        l = max(l, a[i]-i);
    }
    int b = 0;
    for(int i = p-1; i < n; i++){
        b = max(b, min(l-(a[i]-i), i));
    }
    b = max(p-b-1, 0ll);
    cout << b << "\n";
    for(int i = 0; i < b; i++){
        cout << l+i << " ";
    }
    return 0;
}
