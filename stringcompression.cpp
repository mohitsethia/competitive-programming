#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    char a = s[0];
    int x = 1;
    cout << a;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == s[i+1]){
            x++;
        }
        else{
            cout << x << s[i+1];
            x = 1;
        }
    }
    cout << x;
    return 0;
}
