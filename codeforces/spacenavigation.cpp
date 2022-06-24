#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, cnt1[4] = {0}, cnt2[4] = {0};
        cin >> x >> y;
        if(x < 0){
            cnt1[3] = -x;
        }
        else{
            cnt1[2] = x;
        }
        if(y < 0){
            cnt1[1] = -y;
        }
        else{
            cnt1[0] = y;
        }
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                cnt2[3]++;
            }
            else if(s[i] == 'R'){
                cnt2[2]++;
            }
            else if(s[i] == 'D'){
                cnt2[1]++;
            }
            else{
                cnt2[0]++;
            }
        }
        if(cnt2[0] >= cnt1[0] && cnt2[1] >= cnt1[1] && cnt2[2] >= cnt1[2] && cnt2[3] >= cnt1[3]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
