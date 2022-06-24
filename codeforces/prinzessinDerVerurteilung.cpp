#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int cnt[26] = {0};
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(!cnt[i]){
            cout << (char)('a'+i) << "\n";
            return;
        }
    }
    set<string> st;
    for(int i = 0; i < n-1; i++){
        string t = "";
        t += s[i];
        t += s[i+1];
        st.insert(t);
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            string t = "";
            t += (char)(i+'a');
            t += (char)(j+'a');
            if(st.find(t) == st.end()){
                cout << t << "\n";
                return;
            }
        }
    }
    st.clear();
    for(int i = 0; i < n-2; i++){
        string t = "";
        t += s[i];
        t += s[i+1];
        t += s[i+2];
        st.insert(t);
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            for(int k = 0; k < 26; k++){
                string t = "";
                t += (char)('a'+i);
                t += (char)('a'+j);
                t += (char)('a'+k);
                if(st.find(t) == st.end()){
                    cout << t << "\n";
                    return;
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
