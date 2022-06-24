#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    string s;
    cin >> n >> s;
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++){
        ans1 += ((s[i]-'0') != (i&1));
        ans2 += ((s[i]-'0') == (i&1));
    }
    cout << min(ans1, ans2) << "\n";
    return 0;
}
