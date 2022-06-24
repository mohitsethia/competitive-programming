#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int one = 0, zero = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            one++;
        }
        else{
            zero++;
        }
    }
    int ans = n - 2*min(one, zero);
    cout << ans << endl;
    return 0;
}
