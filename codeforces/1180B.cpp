#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0, ind = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0){
            a[i] = -(a[i]+1);
        }
        if(mx < abs(a[i])){
            ind = i;
            mx = abs(a[i]);
        }
    }
    if(n%2){
        a[ind] = -(a[ind]+1);
    }
    for(int i:a) cout << i << " ";
    return 0;
}
