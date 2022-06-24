#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 3; i <= n; i++){
        if(n%i) continue;
        int r = n/i;
        for(int j = 0; j < r; j++){
            int p = 0;
            for(int k = j; k < n; k += r){
                p += a[k];
            }
            if(p == i){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
