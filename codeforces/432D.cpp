#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

vector<int> prefix_func(string s){
    int n = (int)s.length();
    vector<int> lps(n);
    int len = 0, i = 1;
    lps[0] = n;
    while(i < n){
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
                len = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> z_func(string& s, int& n){
    vector<int> z(n);
    z[0] = n;
    int right = 0, left = 0;
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
            if(i + z[k] <= right){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.length();
    vector<int> z = z_func(s, n);
    vector<int> diff(n+1);
    for(int i = 1; i < n; i++){
        diff[z[i]]++;
    }
    for(int i = n-1; i >= 0; i--){
        diff[i] += diff[i+1];
    }
    vector<pair<int, int> > res;
    for(int i = 0; i < n-1; i++){
        if(z[n-i-1] == i+1){
            res.emplace_back(make_pair(i+1, 1+diff[i+1]));
        }
    }
    res.emplace_back(make_pair(n, 1));
    cout << (int)res.size() << "\n";
    for(auto &it: res){
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
