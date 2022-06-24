#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    string s;
    cin >> n >> p >> s;
    int length = s.length();
    length--;
    s[length]++;
    while(length >= 0 && length < n){
        if(s[length]-'a' >= p){
            s[length] = 'a';
            --length;
            if(length >= 0){
                s[length]++;
            }
        }
        else if((length > 0 && s[length] == s[length-1]) || (length > 1 && s[length] == s[length-2])){
            s[length]++;
        }
        else{
            length++;
        }
    }
    if(length < 0){
        cout << "NO\n";
    }
    else{
        cout << s << endl;
    }
    return 0;
}
