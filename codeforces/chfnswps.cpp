#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n], mini = INT_MAX;
        map<int, int> mpa;
        map<int, int> mpb;
        set<int> s;
        vector<int> v;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mpa[a[i]]++;
            s.insert(a[i]);
            mini = min(a[i], mini);
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            mpb[b[i]]++;
            s.insert(b[i]);
            mini = min(b[i], mini);
        }
        int cas = 0, diff = 0;
        for(auto i : s){
            int aa = 0, bb = 0;
            if(mpa.find(i) != mpa.end()){
                aa = mpa[i];
            }
            if(mpb.find(i) != mpb.end()){
                bb = mpb[i];
            }
            if((aa+bb)%2 != 0){
                cas = 1;
                break;
            }
            diff = abs(aa - bb)/2;
            for(int j = 0; j < diff; j++){
                v.push_back(i);
            }
        }
        int sum = 0;
        if(cas != 1){
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size()/2; i++){
                sum += min(2*mini, v[i]);
            }
        }
        if(cas == 1){
            cout << "-1" << endl;
        }
        else{
            cout << sum << endl;
        }
    }
    return 0;
}
