#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    string res = "";
    int i = 0, j = 1;
    while(j < n){
        if(s[i] != s[j]){
            res += s[i];
            res += s[j];
            i = j+1;
            j += 2;
        }
        else{
            j++;
        }
    }
    cout << n - res.size() << "\n";
    cout << res << "\n";
    return 0;
}
