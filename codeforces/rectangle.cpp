#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll col = (y2-y1)/2+1;
    ll total_col = col*(x2-x1+1);
    ll total = total_col - (x2-x1)/2;
    cout << total << endl;
    return 0;
}
