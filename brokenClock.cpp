#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>


using namespace std;

#define ll long long
#define ld long double

#ifdef DEBUG
#define int128 long long
#else
#define int128 __int128
#endif //DEBUG

const int128 bkl = 15709090909091;
const int128 MOD = 12*60*60* (int128)1e9;

bool broke(int128 a, int128 b, int128 c) {
    int128 t = (((b-a) * bkl) % MOD + MOD) % MOD;
    if ((708 * t - c + b) % MOD == 0) {
        ll n = t % (ll)1e9;
        t /= 1e9;
        ll s = t % 60;
        t /= 60;
        ll m = t % 60;
        ll h = t / 60;
        cout << h << " " << m << " " << s << " " << n << "\n";
        return true;
    }
    else 
        return false;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        ll ka, kb, kc;
        cin >> ka >> kb >> kc;
        int128 a = ka, b = kb, c = kc;
        cout << "Case #" << tc << ": ";
        if(broke(a, b, c) || broke(a, c, b) || broke(b, a, c) || broke(b, c, a) || broke(c, a, b) || broke(c, b, a)) {
            
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0;
}


















