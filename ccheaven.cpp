#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int one = 0, zero = 0, flag = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                one++;
                if(one*2 >= i+1){
                    cout << "YES" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag) cout << "NO" << endl;
    }
    return 0;
}
