#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if((int)s.length() == 1){
            cout << (s[0]-'0')-1 << "\n";
            continue;
        }
        string t1 = "", t2 = "";
        for(int i = 0; i < (int)s.length(); i++){
            if(i%2 == 0) t1 += s[i];
            else t2 += s[i];
        }
        cout << (stoi(t1)+1)*(stoi(t2)+1) - 2 << "\n";
    }
    return 0;
}
