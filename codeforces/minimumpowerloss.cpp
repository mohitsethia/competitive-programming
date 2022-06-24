#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, d, x, y, res = 0;
    cin >> n >> d >> x >> y;
    for(int i = 0; i < d; i++){
        int p;
        cin >> p;
        if(abs(p-x) < abs(p-y)){
            res += abs(p-x);
            x = p;
        }
        else{
            res += abs(p-y);
            y = p;
        }
    }
    cout << res << endl;
    return 0;
}
