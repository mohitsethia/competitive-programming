#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, b, a;
    cin >> n >> b >> a;
    vector<int> v(n+1);
    int maxa = a, maxb = b;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a == 0 && b == 0) break;
        if(a == 0 && b > 0){
            b--, ans++;
            if(v[i+1] == 1){
                a = min(a+1, maxa);
            }
        }
        else if(a > 0 && b == 0){
            a--; ans++;
        }
        else if(a < maxa && v[i+1] == 1){
            a = min(a+1, maxa);
            b--; ans++;
        }
        else{
            a--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
