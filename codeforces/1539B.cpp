#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pref(n+1, 0);
    for(int i = 1; i <= n; i++){
        int c = (s[i-1]-'a');
        c++;
        pref[i] = pref[i-1] + c;
    }
    int l, r;
    while(q--){
        cin >> l >> r;
        cout << pref[r]-pref[l-1] << "\n";
    }
    return 0;
}
