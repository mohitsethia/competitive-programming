#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int numberOfString(string s, int k){
    const int mod =  1000000007;
    if(k == 1){
        int x = (s[0]-'a');
        //cout << x << endl;
        return x;
    }
    int v = s[0]-'a';
    int x = ((v*x)%mod + ((x*(x+1)/2)%mod))%mod;
    //cout << x << endl;
    return x;
}
int32_t main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    int result;
    result = numberOfString(s, k);
    cout << result;
    return 0;
}
