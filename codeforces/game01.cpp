#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt1 = 0, cnt0 = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == '1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }
        int ans = min(cnt1, cnt0);
        if(ans%2 == 0){
            cout << "NET" << endl;
        }
        else{
            cout << "DA" << endl;
        }
    }
    return 0;
}
