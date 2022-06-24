#include<iostream>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    string a;
    cin >> a;
    set<char> s;
    for(int i = 0; i < a.length(); i++){
        s.insert(a[i]);
    }
    int l = s.size();
    if(l%2 == 0){
        cout << "CHAT WITH HER!";
    }
    else{
        cout << "IGNORE HIM!";
    }
    return 0;
}
