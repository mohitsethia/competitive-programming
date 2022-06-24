#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    int st = n;
    vector<int> v;
    while(st){
        v.push_back(st%3);
        st /= 3;
    }
    int curr = 1;
    for(int i = 0; i < (int)v.size(); i++){
        curr *= 3;
        if(v[i] != 0) break;
    }
    int ans = n/curr + (n%curr ? 1 : 0);
    cout << ans << "\n";
    return 0;
}
