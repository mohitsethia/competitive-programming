#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int zero = 0, one = 0;
        bool chk = true;
        for(int i = 0; i < k; i++){
            int tmp = -1;
            for(int j = i; j < n; j+=k){
                if(s[j] != '?'){
                    if(tmp != -1 && s[j] - '0' != tmp){
                        chk = false;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if(tmp != -1){
                (tmp == 0 ? zero : one)++;
            }
        }
        if(max(zero, one) > k/2){
            chk = false;
        }
        if(chk){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
