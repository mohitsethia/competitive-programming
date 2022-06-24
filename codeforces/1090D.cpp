#include<iostream>
#include<algorithm>
#include<set>

#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    if(n == (m*(m-1)/2)){
        cout << "NO\n";
        return 0;
    }
    set<pair<int, int> > s;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        s.insert({a, b});
        s.insert({b, a});
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(!s.count({i, j})){
                cout << "YES\n";
                int c = 3;
                for(int k = 0; k < n; k++){
                    if(k == i) cout << "1 ";
                    else if(k == j) cout << "2 ";
                    else cout << c++ << " ";
                }
                cout << "\n";
                c = 3;
                for(int k = 0; k < n; k++){
                    if(k == i || k == j) cout << "1 ";
                    else cout << c++ << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
