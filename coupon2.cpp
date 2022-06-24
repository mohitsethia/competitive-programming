#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int c, d;
    cin >> d >> c;
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    //with coupon
    int sum_c = 0, x = 0, y = 0;
    for(int i = 0; i < 3; i++){
        x += a[i];
        y += b[i];
        sum_c += (a[i]+b[i]);
    }
    if(x < 150){
        sum_c += d;
    }
    if(y < 150){
        sum_c += d;
    }
    
    sum_c += c;
    
    //wihtout coupon
    int sum_d = 0;
    for(int i = 0; i < 3; i++){
        sum_d += a[i];
        sum_d += b[i];
    }
    sum_d += (2*d);
    if(sum_c < sum_d){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    int t = 0;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
