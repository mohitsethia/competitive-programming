#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int finish = 0, damage = 0;
		for (int i = 0; i < n; ++i) {
			int d, h;
			cin >> d >> h;
			finish = max(finish, d);
			damage = max(damage, d - h);
		}
		if (x <= finish) {
			cout << 1 << '\n';
		} else if(damage == 0){
			cout << -1 << '\n';
		}
        else {
			cout << (x - finish + damage - 1) / damage + 1 << '\n';
		}
    }
    return 0;
}
