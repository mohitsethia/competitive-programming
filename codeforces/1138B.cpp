#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    int clown = 0, acrobat = 0, none = 0, both = 0;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++){
        if(s[i] == '1' && t[i] == '1') both++;
        else if(s[i] == '1' && t[i] == '0') clown++;
        else if(s[i] == '0' && t[i] == '1') acrobat++;
        else none++;
    }
    for(int i = 0; i <= clown; i++){
        for(int j = 0; j <= both; j++){
            int x = i+j;
            int y = both-j;
            if(x < y) continue;
            if(acrobat + y < x) continue;
            int a = acrobat - (x-y);
            y += (x-y);
            int c = clown - i;
            int t1 = x + a;
            int t2 = c + y;
            int m = n - t1 - t2;
            if(m == none && t1 <= n/2 && t2 <= n/2){
                clown = i;
                acrobat = a;
                none = max(n/2 - t1, 0ll);
                both = j;
                for(int k = 0; k < n; k++){
                    if(none){
                        if(s[k] == '0' && t[k] == '0'){
                            cout << k+1 << " ";
                            none--;
                        }
                    }
                    if(clown){
                        if(s[k] == '1' && t[k] == '0'){
                            cout << k+1 << " ";
                            clown--;
                        }
                    }
                    if(acrobat){
                        if(s[k] == '0' && t[k] == '1'){
                            cout << k+1 << " ";
                            acrobat--;
                        }
                    }
                    if(both){
                        if(s[k] == '1' && t[k] == '1'){
                            cout << k+1 << " ";
                            both--;
                        }
                    }
                }
                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}
