#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int> (m));
        int mn = INT_MAX;
        bool found = false;
        int sum = 0;
        int neg = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] == 0){
                    found = true;
                }
                else if(a[i][j] < 0) neg++;
                sum += abs(a[i][j]);
                mn = min(mn, abs(a[i][j]));
            }
        }
        if(found || !(neg%2)){
            cout << sum << "\n";
        }
        else{
            sum -= 2*mn;
            cout << sum << "\n";
        }
    }
    return 0;
}
