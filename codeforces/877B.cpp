#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    vector<int> prefa(n+1), prefb(n+1);
    for(int i = 1; i <= n; i++){
        prefa[i] = prefa[i-1] + (s[i-1] == 'a');
        prefb[i] = prefb[i-1] + (s[i-1] == 'b');
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int l = prefa[n]-prefa[j-1] + prefb[j]-prefb[i-1] + prefa[i-1];
            ans = max(ans, l);
        }
    }
    cout << ans << endl;
    return 0;
}
