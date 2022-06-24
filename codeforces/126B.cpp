#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> z_func(string& s){
    int n = (int)s.length();
    vector<int> z(n);
    int left = 0, right = 0;
    for(int i = 1; i < n; i++){
        if(i > right){
            left = right = i;
            while(right < n && s[right] == s[right-left]){
                right++;
            }
            z[i] = right-left;
            right--;
        }
        else{
            int k = i-left;
            if(i+z[k] <= right){
                z[i] = z[k];
            }
            else{
                left = i;
                while(right < n && s[right] == s[right-left]){
                    right++;
                }
                z[i] = right-left;
                right--;
            }
        }
    }
    return z;
}
/*
vector<int> computeLPSArray(string& s, int n){
    vector<int> lps(n);
    int len = 0;
    int i = 1;
    for(i = 1; i < n; ){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    /*
    vector<int> lps = computeLPSArray(s, n);
    int l = lps[n-1];
    for(int i = n-2; i >= 0; i--){
        if(lps[i] == l){
            ans = lps[i];
            break;
        }
    }
    if(ans == -1){
        l = lps[l-1];
    }
    */
    vector<int> z = z_func(s);
    int maxlen = 0;
    for(int i = 1; i < n; i++){
        if(i + z[i] == n && z[i] <= maxlen){
            ans = z[i];
            break;
        }
        maxlen = max(maxlen, z[i]);
    }
    if(ans == 0){
        cout << "Just a legend\n";
    }
    else{
        cout << s.substr(0, ans);
    }
    return 0;
}
