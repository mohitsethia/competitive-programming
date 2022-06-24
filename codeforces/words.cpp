#include<iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int low = 0, up = 0, n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            low++;
        }
        else{
            up++;
        }
    }
    if(low >= up){
        for(int i = 0; i < n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] += 32;
            }
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] -= 32;
            }
        }
    }
    cout << s;
    return 0;
}
