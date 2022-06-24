#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
string check(string s, int k){
    string res = "";
    while(k--){
        res += s;
    }
    return res;
}
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s, t;
        cin >> s >> t;
        int n = (int)s.length(), m = (int)t.length();
        int g = gcd(n, m);
        if(check(s, m/g) == check(t, n/g)){
            cout << check(s, m/g) << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
