#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define int int64_t
int32_t main(){
    int n;
    cin >> n;
    int a[n], b[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for(int i = 0; i < n; i++){
        mp[b[i]] = i;
    }
    for(int i = 0; i < n; i++){
        a[i] = mp[a[i]];
    }
    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(a[i] != i){
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(a[i] != i){
            r = i;
            break;
        }
    }
    if(l == -1 && r == -1){
        cout << "yes" << endl << "1 1" << endl;
    }
    else{
        reverse(a+l, a+r+1);
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(a[i] != i){
                ok = false;
            }
        }
        if(ok){
            cout << "yes" << endl << l+1 << " " << r+1 << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}
