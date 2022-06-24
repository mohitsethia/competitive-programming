#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> s;
        bool consecutive = false;
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
            if(i){
                s.insert(a[i]-a[i-1]);
                if(!consecutive)
                    consecutive = a[i] == a[i-1];
            }
        }
        if((int)s.size() <= 1){
            cout << "0\n";
            continue;
        }
        if((int)s.size() > 2 || consecutive){
            cout << "-1\n";
            continue;
        }
        bool ok = true;
        int p = *s.begin();
        s.erase(s.begin());
        int q = *s.begin();
        int m = q-p;
        int c = q;
        if((p < 0 && q < 0) || (p >= 0 && q >= 0)){
            cout << "-1\n";
            continue;
        }
        if(mx > m){
            cout << "-1\n";
        }
        else{
            cout << m << " " << c << "\n";
        }
    }
    return 0;
}
