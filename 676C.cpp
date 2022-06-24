#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    if(n == 1){
        ans = n;
        cout << ans << endl;
        return 0;
    }
    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b')
            cnt++;
        while(cnt > k){
            if(s[j] == 'b') cnt--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    cnt = 0, j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a')
            cnt++;
        while(cnt > k){
            if(s[j] == 'a') cnt--;
            j++;
        }
        ans = max(ans, i-j+1);
    }
    cout << ans << endl;
    return 0;
}
