#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    int n, q;
    cin >> n;
    char s[100005];
    cin >> s;
    int res = 0;
    map<char, char> mp;
    cin >> q;
    for(int i = 0, j = n-1; i < j; i++, j--){
        cout << s[i] << " " << s[j] << endl;
        if(s[i] != s[j]){
            res++;
            mp[s[i]] = s[j];
            mp[s[j]] = s[i];
        }
    }
    map<char, char> same;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        if(x == 1){
            char a, b;
            cin >> a >> b;
            if(mp[a] == b){
                res--;
                mp.erase(a);
            }
            else if(mp[b] == a){
                res--;
                mp.erase(b);
            }
        }
        else{
            cout << res << endl;
        }
    }
    return 0;
}
