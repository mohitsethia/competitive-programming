#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q, count = 0, ans = 0;
        cin >> n >> q;
        while(q--){
            int f, d;
            cin >> f >> d;
            ans += abs(count-f);
            ans += abs(d-f);
            count = d;
        }
        cout <<  ans << endl;
    }
    return 0;
}
