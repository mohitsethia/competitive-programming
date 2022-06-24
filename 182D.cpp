#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    string s1, s2;
    cin >> s1 >> s2;
    string s = s1 + s2;
    int len = min(s1.size(), s2.size());
    int ans = 0;
    for(int i = 1; i <= len; i++){
        if(s1.size()%i == 0 && s2.size()%i == 0){
            int m = (s1.size()+s2.size())/i;
            bool bad = false;
            for(int j = 0; j < i; j++){
                for(int k = 1; k < m; k++){
                    if(s[j+k*i] != s[j]){
                        bad = true;
                        break;
                    }
                }
                if(bad) break;
            }
            if(!bad) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
