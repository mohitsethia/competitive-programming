#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    while(k--){
        for(int i = 0; i < n-1;){
            if(s[i] == 'B' && s[i+1] == 'G'){
                swap(s[i], s[i+1]);
                i += 2;
            }
            else{
                i++;
            }
        }
    }
    cout << s << endl;
    return 0;
}
