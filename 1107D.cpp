#include<iostream>
#include<algorithm>
#include<map>
#include<numeric>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<char, string> m;
    m['0']="0000";m['1']="0001";m['2']="0010";m['3']="0011";
    m['4']="0100";m['5']="0101";m['6']="0110";m['7']="0111";
    m['8']="1000";m['9']="1001";m['A']="1010";m['B']="1011";
    m['C']="1100";m['D']="1101";m['E']="1110";m['F']="1111";
    string s[n];
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        for(char c: t) s[i] += m[c];
    }
    int g = n;
    for(int i = 0; i < n; i++){
        int c1 = 1, c2 = 1;
        char w1 = s[i][0], w2 = s[0][i];
        for(int j = 1; j < n; j++){
            if(s[i][j] == w1) c1++;
            else{
                g = gcd(g, c1);
                c1 = 1;
                w1 = s[i][j];
            }
            if(s[j][i] == w2) c2++;
            else{
                g = gcd(g, c2);
                c2 = 1;
                w2 = s[j][i];
            }
        }
    }
    cout << g << "\n";
    return 0;
}
