#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int a[10] = {0};
    for(int i = 1; i <= 9; i++){
        cin >> a[i];
    }
    bool done = false;
    for(int i = 0; i < n; i++){
        if(a[s[i]-'0'] > (s[i]-'0')){
            s[i] = a[s[i]-'0'] + '0';
            done = true;
        }
        else if(a[s[i]-'0'] == (s[i]-'0') && done){
            continue;
        }
        else if(done){
            break;
        }
    }
    cout << s << "\n";
    return 0;
}
