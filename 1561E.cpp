#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int a[2050];
void solve(){
    int n;
    cin >> n;
    bool ok = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if((i&1) != (a[i]&1)){
            ok = false;
        }
    }
    if(!ok){
        cout << "-1\n";
        return;
    }
    cout << (n-1)/2 * 5 << "\n";
    for(int i = n; i > 1; i -= 2){
        int x;
        for(int j = 1; j <= i; j++){
            if(a[j] == i){
                x = j;
                break;
            }
        }
        cout << x << " ";
        reverse(a+1, a+x+1);

        for(int j = 1; j <= i; j++){
            if(a[j] == i-1){
                x = j;
                break;
            }
        }
        cout << x-1 << " ";
        reverse(a+1, a+x);

        cout << i << " ";
        reverse(a+1, a+i+1);

        for(int j = 1; j <= i; j++){
            if(a[j] == i){
                x = j;
                break;
            }
        }
        cout << x << " ";
        reverse(a+1, a+x+1);

        cout << i << " ";
        reverse(a+1, a+i+1);
    }
    cout << "\n";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
