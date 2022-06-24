#include<iostream>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, ans=0;
        cin >> n >> k;
        string s;
        cin >> s;
        set<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                st.insert(i);
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                auto it = st.lower_bound(i-k);
                if(it == st.end() or *it > i + k){
                    ans++;
                    s[i] = '1';
                    st.insert(i);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;   
}   
