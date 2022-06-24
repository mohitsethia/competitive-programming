#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    bool ab = false, ba = false;
    int n = s.length();
    for(int i = 0; i < n; i++){
        if(!ab && i < n-1 && s[i] == 'A' && s[i+1] == 'B'){
            ab = true;
            i++;
        }
        else if(ab && i < n-1 && s[i] == 'B' && s[i+1] == 'A'){
            ba = true;
            i++;
        }
        if(ab && ba) break;
    }
    bool ab2 = false, ba2 = false;
    for(int i = 0; i < n; i++){
        if(!ba2 && i < n-1 && s[i] == 'B' && s[i+1] == 'A'){
            ba2 = true;
            i++;
        }
        else if(ba2 && i < n-1 && s[i] == 'A' && s[i+1] == 'B'){
            ab2 = true;
            i++;
        }
        if(ab2 && ba2) break;
    }
    if((ab && ba) || (ab2 && ba2)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
