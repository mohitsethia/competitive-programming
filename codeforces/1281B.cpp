#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, c;
        cin >> s >> c;
        if(s < c){
            cout << s << "\n";
            continue;
        }
        string t = s;
        sort(t.begin(), t.end());
        int n = s.length();
        int pos = -1;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                pos = i;
                break;
            }
        }
        int j = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == t[pos]){
                j = i;
                break;
            }
        }
        if(j != -1){
            swap(s[j], s[pos]);
        }
        if(s < c){
            cout << s << "\n";
        }
        else{
            cout << "---\n";
        }
    }
    return 0;
}
