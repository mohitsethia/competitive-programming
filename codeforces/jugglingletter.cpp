#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k = n;
        map<char, int> mp;
        bool f = true;
        set<char> st;
        while(k--){
            string s;
            cin >> s;
            for(int i = 0; i < s.length(); i++){
                mp[s[i]]++;
                st.insert(s[i]);
            }
        }
        for(auto i : st){
 //           cout << mp[i] << endl;
            if(mp[i] % n != 0){
                f = false;
                break;
            }
        }
        if(!f){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
