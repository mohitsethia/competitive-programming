#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<set>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int p = 0, q = 1;
        int cnt = 0;
        vector<int> res;
        set<int> s;
        while(true){
            int k = 0;
            if(gcd(a[p%n], a[q%n]) == 1 && s.find(p) == s.end() && s.find(q) == s.end()){
                res.emplace_back(p-cnt);
                cnt++;
                s.insert(p);
                s.insert(q);
                p += 2;
                q += 2;
                continue;
            }
            else{
                p++;
                q++;
            }
            while(s.find(p) != s.end() && (int)s.size() > 1){
                p++;
                p%n;
            }
            while(s.find(q) != s.end() && (int)s.size() > 1){
                q++;
                q%n;
            }
        }
    }
    return 0;
}
