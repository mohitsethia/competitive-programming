#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int flag = 0;
    vector<string> v;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == s[i+1]){
            string a = s.substr(i, 2);
            v.push_back(a);
            flag = 1;
        }
    }
    if(flag){
        sort(v.begin(), v.end());
        cout << v[0] << endl;
        return 0;
    }
    for(int i = 0; i < s.length()-2; i++){
        if(s[i] == s[i+2]){
            string a = s.substr(i, 3);
            v.push_back(a);
            flag = 1;
        }
    }
    if(flag){
        sort(v.begin(), v.end());
        cout << v[0] << endl;
        return 0;
    }
    cout << "-1" << endl;
    return 0;
}
