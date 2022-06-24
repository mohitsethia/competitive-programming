#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    set<char> s;
    for(char c = 'a'; c <= 'z'; c++){
        s.insert(c);
    }
    int ans = 0;
    for(int p = 0; p < n; p++){
        char type;
        cin >> type;
        if(type == '.'){
            string st;
            cin >> st;
            for(auto &i: st){
                s.erase(i);
            }
        }
        else if(type == '!'){
            if((int)s.size() == 1ll){
                ans++;
            }
            string st;
            cin >> st;
            bool seen[26] = {0};
            for(auto &i: st){
                seen[i-'a'] = true;
            }
            for(int i = 0; i < 26; i++){
                if(!seen[i]){
                    s.erase(i+'a');
                }
            }
        }
        else{
            char ch;
            cin >> ch;
            if((int)s.size() == 1ll && *s.begin() != ch)
                ans++;
            else
                s.erase(ch);
        }
    }
    cout << ans << "\n";
    return 0;
}
