#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(a[0]);
    v.push_back(a[n-1]);
    for(int i = 1; i < n-1; i++){
        v.push_back(max(a[i], a[i+1]));
    }
    sort(v.begin(), v.end());
    cout << v[0] << "\n";
    return 0;
}
