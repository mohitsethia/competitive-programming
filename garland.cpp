#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> cnta(26, 0), cntb(26, 0);
    for(int i = 0; i < a.length(); i++){
        cnta[a[i]-'a']++;
    }
    for(int i = 0; i < b.length(); i++){
        cntb[b[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(cntb[i] && !cnta[i]){
            ans = 0;
            break;
        }
        ans += min(cnta[i], cntb[i]);
    }
    if(ans)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
