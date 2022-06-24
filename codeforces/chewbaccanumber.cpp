#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int x = s[i] -48;
        if(9-x < x){
            if(9-x == 0 && i == 0){
                continue;
            }
            s[i] = (9-x) + '0';
        }
    }
    cout << s << endl;
    return 0;
}
