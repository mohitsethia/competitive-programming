#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<climits>
#include<vector>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int maxx = INT_MIN, missing = -1;
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
            maxx = max(maxx, a[i]);
        }
        int cnt = 0, f = 0;
        // set<int> s(a.begin(), a.end());
        while(1){
            if(s.find(cnt) == s.end()){
                missing = cnt;
                f = 1;
            }
            else{
                cnt++;
            }
            if(f) break;
        }
        int m = (maxx+missing+1)/2;
        if(s.find(m) != s.end()){
            cout << s.size() << endl;
        }
        else{
            int done = 0;
            if(missing > maxx){
                cout << s.size()+k << endl;
                continue;
            }
            if(k > 0){
                s.insert(m);
                k--;
                while(k-- > 0){
                    cnt = missing;
                    f = 0;
                    while(1){
                        if(s.find(cnt) == s.end()){
                            missing = cnt; f = 1;
                        }
                        else cnt++;
                        if(f) break;
                    }
                    for(auto& c: s){
                        maxx = max(maxx, c);
                    }
                    m = (maxx+missing+1)/2;
                    if(s.find(m) != s.end()){
                        cout << s.size() << endl;
                        done = 1;
                        break;
                    }
                    s.insert(m);
                }
            }
            if(!done) cout << s.size() << endl;
        }
    }
    return 0;
}
