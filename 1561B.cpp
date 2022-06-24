#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    int n = a+b;
    set<int> s;
    for(int a_win_away = 0; a_win_away <= n/2; a_win_away++){
        int a_win_at_home = a - a_win_away;
        int b_win_at_home = n/2 - a_win_away;
        int b_win_away = b - b_win_at_home;
        if(min(a_win_away, min(a_win_at_home, min(b_win_away, b_win_at_home))) < 0) continue;
        if(a_win_away + a_win_at_home == a && b_win_away + b_win_at_home == b){
            s.insert(a_win_away + b_win_away);
        }
    }
    for(int a_win_away = 0; a_win_away <= (n+1)/2; a_win_away++){
        int a_win_at_home = a - a_win_away;
        int b_win_at_home = (n+1)/2 - a_win_away;
        int b_win_away = b - b_win_at_home;
        if(min(a_win_away, min(a_win_at_home, min(b_win_away, b_win_at_home))) < 0) continue;
        if(a_win_away + a_win_at_home == a && b_win_away + b_win_at_home == b){
            s.insert(a_win_away + b_win_away);
        }
    }
    cout << s.size() << "\n";
    for(auto it: s){
        cout << it << " ";
    }
    cout << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
