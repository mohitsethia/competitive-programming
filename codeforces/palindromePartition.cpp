#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
    int minCut(string &s){
        vector<int> cut(s.length());
        vector<vector<bool> > pal(s.length(), vector<bool>(s.length(), false));
        for(int i = 0; i < (int)s.length(); i++){
            int minCut = i;
            for(int j = 0; j <= i; j++){
                if(s[i] == s[j] && (i-j < 2 || pal[j+1][i-1])){
                    pal[j][i] = true;
                    minCut = min(minCut, j == 0 ? 0 : cut[j-1]+1);
                }
            }
            cut[i] = minCut;
        }
        return cut[s.length()-1];
    }
};

int main(){
    string s;
    cin >> s;
    Solution *obj = new Solution();
    cout << obj->minCut(s) << "\n";
    return 0;
}
