#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    int freq[26];
    memset(freq, 0, sizeof(freq));
    if(s.length() % k != 0){
        cout << "-1" << endl;
        return 0;
    }
    else{
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(freq[s[i] - 'a'] % k != 0){
                cout << "-1" << endl;
                return 0;
            }
        }
        sort(s.begin(), s.end());
        int i, j = 0;
        for(int j = 0; j < k; j++){
            for(int i = 0; i < s.length(); i+=k){
                cout << s[i];
            }
        }
    }
    return 0;
}
