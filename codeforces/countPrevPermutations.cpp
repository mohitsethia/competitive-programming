#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
    const int MOD = 1e9+7;
    vector<vector<int>> C;
    public:
    void Choose(){
        int N = 3001;
        C = vector<vector<int> >(N, vector<int>(N));
        for(int i = 0; i < N; i++){
            C[i][0] = C[i][i] = 1;
            for(int j = 1; j < i; j++){
                C[i][j] = (C[i-1][j-1] + C[i-1][j]);
                if(C[i][j] < 0) C[i][j] += MOD;
            }
        }
    }
    int makeStringSorted(string &s){
        long long ans = 0;
        int n = s.length();
        vector<int> freq(26);
        for(int i = n-1; i >= 0; --i){
            freq[s[i]-'a']++;
            for(int nw = 0; nw < s[i]-'a'; nw++){
                if(freq[nw] > 0){
                    long long ways = 1;
                    freq[nw]--;
                    int len = n-i-1;
                    for(int c = 0; c < 26; c++){
                        ways *= C[len][freq[c]];
                        ways %= MOD;
                        len -= freq[c];
                    }
                    freq[nw]++;
                    ans += ways;
                    if(ans < 0) ans += MOD;
                    if(ans >= MOD) ans -= MOD;
                }
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    Solution obj;
    obj.Choose();
    while(t--){
        string s;
        cin >> s;
        cout << obj.makeStringSorted(s) << "\n";
    }
    return 0;
}
