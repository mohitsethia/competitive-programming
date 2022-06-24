#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n == 1){
        cout << "-1\n";
        return 0;
    }
    if(a[0] == a[n-1]){
        cout << 1 << endl;
        cout << a[0] << endl;
        return 0;
    }
    vector<int> v;
    sort(a.begin(),a.end());
    for(int i = 1; i < n; i++){
        v.push_back(a[i]-a[i-1]);
    }
    sort(v.begin(), v.end());
    if(n == 2 && v[0]%2 == 0){
        cout << 3 << endl;
        cout << a[0] - v[0] << " " << (a[1]+a[0])/2 << " " << a[1]+v[0] << endl;
        return 0;
    }
    if(v.size() > 2 && v[0] != v[v.size()-2]){
        cout << 0 << endl;
        return 0;
    }
    if(v.size() > 1 && v[v.size()-1] > v[0]){
        if(v[v.size()-1] != 2*v[0]){
            cout << "0\n";
            return 0;
        }
        else{
            cout << 1 << endl;
            for(int i = 1; i < n; i++){
                if(a[i]-a[i-1] != v[0]){
                    cout << a[i-1]+v[0] << endl;
                    return 0;
                }
            }
        }
    }
    cout << 2 << endl;
    cout << a[0] - v[0] << " " << a[n-1] + v[0] << endl;
    return 0;
}
