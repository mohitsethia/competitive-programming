#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<set<int> > a(26);
    for(int i = 0; i < (int)s.length(); i++){
        a[s[i]-'a'].insert(i);
    }
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int pos;
            char c;
            cin >> pos >> c;
            int idx = pos-1;
            a[s[idx]-'a'].erase(idx);
            s[idx] = c;
            a[c-'a'].insert(idx);
        }
        else{
            int l, r;
            cin >> l >> r;
            int cnt = 0;
            for(int i = 0; i < 26; i++){
                auto st = a[i].lower_bound(l-1);
                if(st != a[i].end() && *st <= r-1){
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}
