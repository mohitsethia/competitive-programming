#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    string s;
    cin >> s;
    int totalG = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G'){
            totalG++;
            l[i] = 1;
            if(i) l[i] += l[i-1];
        }
    }
    if(totalG == 0){
        cout << "0\n";
        return 0;
    }
    if(totalG == n){
        cout << n << "\n";
        return 0;
    }
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'G'){
            r[i] = 1;
            if(i < n-1) r[i] += r[i+1];
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        int temp = (i ? l[i-1] : 0) + (i+1 < n ? r[i+1] : 0);
        res = max(res, 1+temp);
    }
    res = min(res, totalG);
    cout << res << "\n";
    return 0;
}
