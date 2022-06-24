#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool isPalindrome(string &s){
    int n = s.length();
    for(int i = 0; i <= n/2; i++){
        if(s[i] == s[n-i-1]){
        }
        else{
            return false;
        }
    }
    return true;
}

int kmp(string &s){
    vector<int> lps((int)s.size());
    for(int i = 1; i < (int)s.size(); i++){
        int prev_idx = lps[i-1];
        while(prev_idx > 0 && s[i] != s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }
        lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
    }
    return lps[lps.size()-1];
}

int largest_pal(string s){
    string t = s + '&';
    reverse(s.begin(), s.end());
    t += s;
    return kmp(t);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int l = 0;
        int i = 0, j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                l++;
            }
            else{
                break;
            }
            i++;
            j--;
        }
        string t = s.substr(l, n-2*l);
        string ans = s.substr(0, l);
        if((int)t.size() > 0){
            int l_pre = largest_pal(t);
            reverse(t.begin(), t.end());
            int l_suf = largest_pal(t);
            if(l_pre > l_suf){
                reverse(t.begin(), t.end());
                ans += t.substr(0, l_pre);
            }
            else{
                ans += t.substr(0, l_suf);
            }
        }
        ans += s.substr(n-l, l);
        cout << ans << "\n";
    }
    return 0;
}
