#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int l, r, m, a, b, c;
        cin >> l >> r >> m;
        for(int i = l; i <= r; i++){
            int un = m/i;
            int high = un + 1;
            int less = un*i;
            int more = high * i;
            int diff = m-less;
            if(diff <= r-l && less > 0){
                a = i;
                b = r;
                c = r-diff;
                break;
            }
            else if(more - m <= r-l){
                a = i;
                b = l;
                c = l+more-m;
                break;
            }
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
