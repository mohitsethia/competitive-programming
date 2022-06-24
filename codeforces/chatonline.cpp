#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int p, q, r, l, ans = 0, a, b, t[2010] = {0};
    cin >> p >> q >> l >> r;
    int c[q], d[q];
    for(int i = 0; i < p; i++){
        cin >> a >> b;
        for(int j = a; j <= b; j++){
            t[j] = 1;
        }
    }
    for(int i = 0; i < q; i++){
        cin >> c[i] >> d[i];
    }
    for(int i = l; i <= r; i++){
        int f = 1;
        for(int j = 0; j < q && f; j++){
            for(int k = c[j]+i; k <= d[j]+i; k++){
                if(t[k]){
                    f = 0;
                    break;
                }
            }
        }
        if(!f){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
