#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string s;
    cin >> s;
    int a[10] = {0};
    for(int i = 0; i < s.length(); i++){
        a[s[i]-'0']++;
    }
    if(a[4] != 0 && a[4] >= a[7]){
        cout << "4";
    }
    else if(a[7] != 0 && a[7] > a[4]){
        cout << "7";
    }
    else{
        cout << "-1";
    }
    return 0;
}
