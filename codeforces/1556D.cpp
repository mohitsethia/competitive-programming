#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int And(int a, int b){
    cout << "and " << a+1 << " " << b+1 << endl;
    int res;
    cin >> res;
    return res;
}

int Or(int a, int b){
    cout << "or " << a+1 << " " << b+1 << endl;
    int res;
    cin >> res;
    return res;
}

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int a01 = And(0, 1) + Or(0, 1);
    int a12 = And(2-1, 3-1) + Or(2-1, 3-1);
    int a02 = And(1-1, 3-1) + Or(1-1, 3-1);
    a[1] = (a01+a12-a02)/2;
    a[0] = a01 - a[1];
    a[2] = a12 - a[1];
    for(int i = 3; i < n; i++){
        int rt1 = And(i, i-1) + Or(i, i-1);
        a[i] = rt1 - a[i-1];
    }
    sort(a.begin(), a.end());
    k--;
    cout << "finish " <<  a[k] << endl;
    return 0;
}
