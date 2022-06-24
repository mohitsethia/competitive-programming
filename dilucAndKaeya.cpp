#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int D = 0, K = 0;
        map<pair<int, int>, int> mp;
        for(int i = 0; i < n; i++){
            if(s[i] == 'D'){
                D++;
            }
            else{
                K++;
            }
            int g = gcd(D, K);
            int d = D/g;
            int k = K/g;
            mp[{d, k}]++;
            cout << mp[{d, k}] << " ";
        }
        cout << endl;
    }
    return 0;
}
