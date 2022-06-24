#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    char s[n+1];
    for(int i = 1; i <= n-1; i++) cin >> s[i];
    vector<int> a(n+1), b(n+1), ans(n+1);
    a[1] = 1;
    for(int i = 2; i <= n; i++){
        if(s[i-1] == 'R') a[i] = a[i-1]+1;
        else if(s[i-1] == '=') a[i] = a[i-1];
        else a[i] = 1;
    }
    b[n] = 1;
    ans[n] = a[n];
    for(int i = n-1; i >= 1; i--){
        if(s[i] == 'L') b[i] = b[i+1]+1;
        else if(s[i] == '=') b[i] = b[i+1];
        else b[i] = 1;
        ans[i] = max(a[i], b[i]);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
