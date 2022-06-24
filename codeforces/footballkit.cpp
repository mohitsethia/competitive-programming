#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define int long long
#define MAXX 100005
int32_t main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n), home(n, 0), away(n, 0), cnt(100005, 0);
//    for(int i = 0; i < n; i++){
//        cnt[x[i]] = 0;
//    }
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        cnt[x[i]]++;
    }
    for(int i = 0; i < n; i++){
        home[i] = n-1;
        home[i] += cnt[y[i]];
        away[i] = 2*(n-1) - home[i];
        cout << home[i] << " " << away[i] << endl;
    }
    return 0;
}
