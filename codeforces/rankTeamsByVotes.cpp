#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
    string rankTeams(vector<string> &votes){
        vector<vector<int> > count(26, vector<int>(27));
        for(char &c: votes[0]){
            count[c-'A'][26] = c;
        }
        for(string &vote: votes){
            for(int i = 0; i < (int)vote.length(); i++){
                --count[vote[i]-'A'][i];
            }
        }
        sort(count.begin(), count.end());
        string res;
        for(int i = 0; i < (int)votes[0].length(); i++){
            res += count[i][26];
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> votes(n);
    for(int i = 0; i < n; i++) cin >> votes[i];
    Solution obj;
    cout << obj.rankTeams(votes) << "\n";
    return 0;
}
