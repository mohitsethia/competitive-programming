#pragma GCC optimize("O2")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<numeric>

using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> b(n+2);
        for(int& x: b){
            cin >> x;
        }
        bool found = false;
        multiset<int> s(b.begin(), b.end());
        long long sum = accumulate(b.begin(), b.end(), 0LL);

        for(int& x: b){
            s.erase(s.find(x));
            sum -= x;
            if(sum%2 == 0 && s.find(sum/2) != s.end()){
                s.erase(s.find(sum/2));
                for(int it: s){
                    cout << it << " ";
                }
                cout << endl;
                found = true;
                break;
            }
            sum += x;
            s.insert(x);
        }
        if(!found){
            cout << "-1" << endl;
        }
    }
    return 0;
}
