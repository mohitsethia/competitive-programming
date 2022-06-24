#include<iostream>
#include<algorithm>

#define int long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        int n, m, p;
        cin >> n >> m >> p;
        int x;
        int i = 0;
        int first = 0;
        bool found = false;
        for(i = 0; i < n; i++){
            cin >> x;
            if(x%p && !found){
                first = i;
                found = true;
            }
        }
        for(i = 0; i < m; i++){
            cin >> x;
            if(x%p){
                cout << first+i << "\n";
                return 0;
            }
        }
        cout << first << "\n";
    return 0;
}
