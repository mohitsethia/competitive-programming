#include<iostream>
#include<algorithm>

using namespace std;

#define int long long 

const int N = 1e9;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int ra = 0;
    int ma1 = -N;
    int mi1 = N;
    int ma2 = -N;
    int mi2 = N;
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        int d; cin >> d;
        if (d == 2) {
            mi2 = min(mi2, ra);
            ma2 = max(ma2, ra);
        } else {
            mi1 = min(mi1, ra);
            ma1 = max(ma1, ra);
        }
        ra += c;
    }
    if (ma2 == -N) {
        cout << "Infinity";
    } else if(ma2 >= mi1) {
        cout << "Impossible";
    }else {
        cout << 1899 - ma2 + ra;
    }
}
