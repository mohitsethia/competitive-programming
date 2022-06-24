#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int divisible(string& s){
    int n = s.length();
    int ans = -1;
    for(int i = 0; i < n; i++){
        int c1 = s[i]-'0';
        if(c1 == 0 || c1 == 8){
            ans = c1;
            return ans;
        }
        for(int j = i+1; j < n; j++){
            int c2 = s[j]-'0';
            int p = c1*10 + c2;
            if((p)%8 == 0){
                ans = p;
                return ans;
            }
            for(int k = j+1; k < n; k++){
                int c3 = s[k]-'0';
                int q = p*10 + c3;
                if(q%8 == 0){
                    ans = q;
                    return ans;
                }
            }
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int ans = divisible(s);
    if(ans == -1){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        cout << ans << endl;
    }
    return 0;
}
