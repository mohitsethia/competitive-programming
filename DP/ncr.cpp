#include <bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
#define int long long
signed main() {
	//code
	int t;
	cin >> t;
	while(t--){
	    int n, r;
	    cin >> n >> r;
	    cpp_int p = 1;
	    cpp_int q = 1;
	    for(int i = 0; i < r; i++){
	        p *= (n-i);
	        q *= (i+1);
	    }
	    cout << (p/q)%1000000007 << endl;
	}
	return 0;
}
