#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int cnt_0 = 0;
        for(int i=0; i < n; i++){
            if(s[i] == '0'){
                cnt_0++;
            }
        }
        int cnt_1 = 0, is_palindrome = 1;
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n-i-1]) is_palindrome = 0;
            if((s[i] == '1' || s[n-i-1] == '1') && s[i] != s[n-i-1]){
                cnt_1++;
            }
        }
        if(is_palindrome){
            if(cnt_0 > 1 && cnt_0%2){
                puts("ALICE");
            }
            else{
                puts("BOB");
            }
            continue;
        }
        if(cnt_0 == 2 && cnt_1 == 1){
            puts("DRAW");
            continue;
        }
        puts("ALICE");
    }
    return 0;
}
