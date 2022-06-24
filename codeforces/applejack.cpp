#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    unordered_map<ll, ll> mp, freq;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        mp[x]++;
        freq[mp[x]]++;
    }
    ll q;
    cin >> q;
    while(q--){
        char t;
        ll x;
        cin >> t >> x;
        if(t == '+'){
            mp[x]++;
            freq[mp[x]]++;
        }
        if(t == '-'){
            freq[mp[x]]--;
            mp[x]--;
        }
        if(freq[8] > 0 || (freq[6] > 0 && freq[2] > 1) || freq[4] > 1 || (freq[4] > 0 && freq[2] > 2)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}























/*#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	unordered_map <int, int> m, cnt;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		m[x]++;
		cnt[m[x]]++;
        cout << m[x] << " " << cnt[m[x]] << endl;
	}
	int q;
	cin >> q;
	while(q--){
		char ch;
		int x;
		cin >> ch >> x;
		if(ch == '+') m[x]++, cnt[m[x]]++;
		else cnt[m[x]]--, m[x]--;
		
		if((cnt[8] > 0) || (cnt[6] > 0 && cnt[2] > 1) || (cnt[4] > 1) || (cnt[4] > 0 && cnt[2] > 2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

*/
