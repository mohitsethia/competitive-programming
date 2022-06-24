#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

const int N = 2e5+10;

int a[N], p[N], s[N];

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= 2*n; i++){
            cin >> a[i];
            p[i] = p[i-1] + (a[i] == 1 ? 1: -1);
        }
        map<int, int> pos = {{0, 0}};
        s[2*n+1] = 0;
        for(int i = 2*n; i >= n+1; i--){
            s[i] = s[i+1] + (a[i] == 1 ? -1: 1);
            pos[s[i]] = (2*n - i + 1);
        }
        int best = 0;
        for(int i = 0; i <= n; i++){
            if(pos.count(p[i])){
                best = max(best, i+pos[p[i]]);
            }
        }
        cout << 2*n - best << "\n";
    }
    return 0;
}
