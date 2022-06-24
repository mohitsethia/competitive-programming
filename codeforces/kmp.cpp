#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    vector<int> createArray(string pat){
        int i = 1, j = 0;
        int n = pat.length();
        vector<int> lps(n);
        while(i < n){
            if(pat[i] == pat[j]){
                lps[i] = j+1;
                i++;
                j++;
            }
            else{
                if(j == 0){
                    lps[i++] = 0;
                }
                else
                    j = lps[j-1];
            }
        }
        return lps;
    }

    public:

    vector<int> kmpSearch(string text, string pat){
        vector<int> lps = createArray(pat);
        int i = 0, j = 0;
        vector<int> res;
        while(i < (int)text.length() && j < (int)pat.length()){
            if(text[i] == pat[j]){
                i++, j++;
            }
            if(j == (int)pat.length()){
                res.push_back(i-j);
                j = lps[j-1];
            }
            else if(i < (int)text.length() && pat[j] != text[i]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
        return res;
    }
};

int main(){
    string s, t;
    cin >> s >> t;
    Solution *obj = new Solution();
    vector<int> res = obj->kmpSearch(s, t);
    if(res.size()){
        cout << "Present\n";
        for(int index: res){
            cout << index << " ";
        }
        cout << "\n";
    }
    else{
        cout << "Not Present\n";
    }
    return 0;
}


/*
//Knuth Morris Pratt Algorithm
#include<iostream>
using namespace std;
#define MAX_N 100005
int reset[MAX_N];
void KMPpreprocess(string pat){
int i = 0, j = 1;
reset[0] = -1;
while(i < pat.size()){
while(j >= 0 && pat[i] != pat[j]){
j = reset[j];
}
i++;
j++;
reset[i] = j;
}
}
void KMPsearch(string str, string pat){
KMPpreprocess(pat);
int i = 0, j = 0;
while(i < str.size()){
while(j >= 0 && str[i] != pat[j]){
j = reset[j];
}
i++;
j++;
if(j == pat.size()){
cout << "Pattern found at " << (i-j) << endl;
j = reset[j];
}
}
}
int main(){
for(int i = 0; i < MAX_N; i++){
reset[i] = -1;
}
string str, pat;
cin >> str >> pat;
KMPsearch(str, pat);
return 0;
}
 */
