#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    bool flag = true;
    for(int i = 2; i < len; i++){
        if(((s[i-1] + s[i-2])%26 + 'A') != (s[i])){
            puts("NO");
            return 0;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}
