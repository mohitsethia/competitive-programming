#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
int solve(){
    int X, Y;
    string s;
    cin >> X >> Y >> s;
    int ans = 0;
    char previousChar = 'A';
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'C'){
            if(previousChar == 'J'){
                ans += Y;
            }
            previousChar = 'C';
        }
        else if(s[i] == 'J'){
            if(previousChar == 'C'){
                ans += X;
            }
            previousChar = 'J';
        }
    }
    return ans;
}
int main(){
    int t, tc = 1;
    cin >> t;
    while(tc <= t){
        cout << "Case #" << tc++ << ": " << solve() << "\n";
    }
    return 0;
}
