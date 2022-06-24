#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool bad = false;
        for(int i = 0; i < n; i++){
            if(b[i]-a[i] > 1 || b[i]-a[i] < 0){
                bad = true;
                break;
            }
        }
        cout << (!bad ? "YES\n" : "NO\n");
    }
    return 0;
}
