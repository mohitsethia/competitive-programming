#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 0, r = n-1;
    string res = "";
    int lastInt = 0;
    while(l <= r){
        vector<pair<int, char> > comp;
        if(lastInt < a[l]) comp.push_back({a[l], 'L'});
        if(lastInt < a[r]) comp.push_back({a[r], 'R'});
        sort(comp.begin(), comp.end());
        if((int)comp.size() == 2 && comp[0].first != comp[1].first){
            comp.pop_back();
        }
        if((int)comp.size() == 1){
            lastInt = comp[0].first;
            res += comp[0].second;
            l += comp[0].second == 'L';
            r -= comp[0].second == 'R';
        }
        else if((int)comp.size() == 2){
            int i = 1, j = 1;
            while(l + i <= r && a[l+i] > a[l+i-1]) i++;
            while(r - j >= l && a[r-j] > a[r-j+1]) j++;
            if(i > j){
                res += string(i, 'L');
            }
            else{
                res += string(j, 'R');
            }
            break;
        }
        else{
            break;
        }
    }
    cout << res.length() << "\n";
    cout << res << "\n";
    return 0;
}
