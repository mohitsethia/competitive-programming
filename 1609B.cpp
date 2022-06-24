#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    int res = 0;
    for(int i = 0; i+2 < n; i++){
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c'){
            res++;
        }
    }
    while(q--){
        int pos;
        char ch;
        cin >> pos >> ch;
        pos--;
        if(s[pos] == ch) {
            cout << res << "\n";
        }
        else{
            if(s[pos] == 'a' && pos+2 < n){
                if(s[pos+1] == 'b' && s[pos+2] == 'c') res--;
            }
            else if(s[pos] == 'b' && pos-1 >= 0 && pos+1 < n){
                if(s[pos-1] == 'a' && s[pos+1] == 'c') res--;
            }
            else if(s[pos] == 'c' && pos-2 >= 0){
                if(s[pos-1] == 'b' && s[pos-2] == 'a') res--;
            }
            s[pos] = ch;
            if(ch == 'a' && pos+2 < n){
                if(s[pos+1] == 'b' && s[pos+2] == 'c') res++;
            }
            else if(ch == 'b' && pos-1 >= 0 && pos+1 < n){
                if(s[pos-1] == 'a' && s[pos+1] == 'c') res++;
            }
            else if(ch == 'c' && pos-2 >= 0){
                if(s[pos-1] == 'b' && s[pos-2] == 'a') res++;
            }
            cout << res << "\n";
        }
    }
    return 0;
}
