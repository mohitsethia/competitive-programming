#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, cnt = 0, l = 0;
        string s;
        cin >> n >> s;
        l = s.length();
        for(int i = l-1; i >= 0; i--){
            if(s[i] == ')'){
                cnt++;
            }
            else{
                break;
            }
        }
        if(cnt > l-cnt){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
