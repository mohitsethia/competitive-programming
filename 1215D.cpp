#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int balance = 0;
    for(int i = 0; i < n; i++){
        int w = i < n/2 ? 1 : -1;
        if(s[i] == '?') balance += 9*w;
        else balance += (s[i]-'0')*2*w;
    }
    cout << (balance == 0 ? "Bicarp" : "Monocarp") << "\n";
    return 0;
}
