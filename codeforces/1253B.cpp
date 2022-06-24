#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 1e5+10;

int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    set<int> seen, have;
    bool ok = true;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt++;
        if(a[i] > 0){
            if(seen.count(a[i])){
                ok = false;
                break;
            }
            seen.insert(a[i]);
            have.insert(a[i]);
        }
        else{
            a[i] = -a[i];
            if(!have.count(a[i])){
                ok = false;
                break;
            }
            have.erase(a[i]);
        }
        if(have.empty()){
            ans.push_back(cnt);
            cnt = 0;
            seen.clear();
        }
    }
    ok &= (cnt == 0);
    if(!ok){
        cout << "-1\n";
    }
    else{
        cout << ans.size() << "\n";
        for(int i: ans){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
