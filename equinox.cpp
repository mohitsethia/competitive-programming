#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        int sarthak = 0, anuradha = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            if(s[0] == 'E' || s[0] == 'Q' || s[0] == 'U' || s[0] == 'I' || s[0] == 'N' || s[0] == 'O' || s[0] == 'X'){
                sarthak += a;
            }
            else anuradha += b;
        }
        if(anuradha > sarthak) cout << "ANURADHA" << endl;
        else if(anuradha < sarthak) cout << "SARTHAK" << endl;
        else cout << "DRAW" << endl;
    }
    return 0;
}
