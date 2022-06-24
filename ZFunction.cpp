#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> z_func(string &s){
    int n = (int) s.length();
    vector<int> z(n);
    int left  = 0;
    int right = 0;
    z[0] = 0;
    for(int k = 1; k < n; k++){
        if(k > right){
            left = right = k;
            while(right < n && s[right] == s[right-left]){
                right++;
            }
            z[k] = right-left;
            right--;
        }
        else{
            int k1 = k-left;
            if(k + z[k1] <= right){
                z[k] = z[k1];
            }
            else{
                left = k;
                while(right < n && s[right] == s[right-left]){
                    right++;
                }
                z[k] = right-left;
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
    string text, pattern;
    cin >> text >> pattern;
    string s = pattern + "$" + text;
    vector<int> z = z_func(s);
    for(int i = 0; i < (int)z.size(); i++){
        if(z[i] == pattern.length()){
            cout << i - (pattern.length()+1) + 1 << " ";
        }
    }
    return 0;
}
