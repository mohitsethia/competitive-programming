#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int  n;
        cin >> n;
        vector<pair<int, int> > a(n+1);
        int sum = 0;
        int c = 1;
        for(int i = 1; i <= n; i++){
            cin >> a[i].first;
            a[i].second = i;
            sum += a[i].first;
        }
        sort(a.begin(), a.end());
        for(int i = n-1; i >= 1; i--){
            sum -= a[i+1].first;
            if(sum < a[i+1].first){
                break;
            }
            else{
                c++;
            }
        }
        vector<int> v;
        for(int i = n; i > n-c; i--){
            v.push_back(a[i].second);
        }
        sort(v.begin(), v.end());
        cout << (int)v.size() << endl;
        for(int i = 0; i < (int)v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

