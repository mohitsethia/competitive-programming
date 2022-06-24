/*
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s;
    cin >> s;
    int ms = 0, cs = 0, k = 0;
    // abcdecfg
    for(int i = 0; i < s.length() - 1; i++){
        cs = 0;
        for(int j = i; j < s.length(); j++){
            int count = 0;
            for(k = i; k < j; k++){
                if(s[k] == s[j]){
                    count = 1;
                    break;
                }
            }
            if(count == 1){
                i = k;
                break;
            }
            else{
                cs++;
            }
            if(cs > ms){
                ms = cs;
            }
        }
    }
    cout << ms;
    return 0;
}
*/
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        int freq[3];
        cin >> a;
        for(int i = 0; i < a.length(); i++){
            freq[a[i]]++;
        }
        for(int i = 0; i < 3; i++){
            if(freq[i] > 0){
                cout << 0 << endl;
                continue;
            }
        }
        int n = a.length();
        int current_len = 1;
        int max_len = 1;
        int visited[256];
        for(int i = 0; i < 256; i++){
            visited[i] = -1;
        }
        visited[a[0]] = 0;
        for(int i = 1; i < n; i++){
            int last_occ = visited[a[i]];
            if(last_occ == -1 || i - current_len > last_occ){
                current_len++;
                max_len = max(current_len, max_len);
            }
            else{
                if(current_len > max_len){
                    max_len = current_len;
                }
                current_len = i - last_occ;
            }
            visited[a[i]] = i;
        }
        if(current_len > max_len){
            max_len = current_len;
        }
        cout << max_len << endl;
    }
    return 0;   
}
