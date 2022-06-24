#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(){
    string s;
    cin >> s;
    map<char, int> mp;
    for(int i = 0; i < s.length(); i++){
        mp[s[i]]++;
    }
    int cnt = 0;
    for(auto it: mp){
        if(it.second % 2 != 0){
            cnt++;
        }
    }
    if(cnt%2 || cnt == 0){
        cout << "First" << endl;
    }
    else{
        cout << "Second" << endl;
    }
    return 0;
}
