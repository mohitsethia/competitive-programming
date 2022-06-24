#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int i = 0, j = n-1;
        pair<int, int> deleted = {-1, -1};
        while(i < j){
            if(a[i] != a[j]){
                    deleted = {a[i], a[j]};
                    break;
            }
            else i++, j--;
        }
        bool bad = false;
        i = 0, j = n-1;
        while(i < j){
            if(a[i] == deleted.first) i++;
            else if(a[j] == deleted.first) j--;
            else if(a[i] != a[j]){
                bad = true;
                break;
            }
            else i++, j--;
        }
        if(!bad){
            cout << "YES\n";
            continue;
        }
        i = 0, j = n-1;
        bad = false;
        while(i < j){
            if(a[i] == deleted.second) i++;
            else if(a[j] == deleted.second) j--;
            else if(a[i] != a[j]){
                bad = true;
                break;
            }
            else i++, j--;
        }
        if(bad) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
