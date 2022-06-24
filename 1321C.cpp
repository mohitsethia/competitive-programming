#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for(int i = 25; i > 0; i--){
        char j = 'a'+i;
        char k = 'a'+(i-1);
        while(true){
            int cnt = 0;
            for(int p = 0; p < (int)s.length(); p++){
                if(s[p] == j && ((p-1 >= 0 && s[p-1] == k) || (p+1 < (int)s.length() && s[p+1] == k))){
                    s.erase(p, 1);
                    cnt++;
                }
            }
            if(!cnt) break;
            res += cnt;
        }
    }
    cout << res << "\n";
    return 0;
}
