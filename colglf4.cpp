#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;

#define int long long

int calculate(int res, int N, int E, int H, int A, int B, int C){
	if(N <= 0){
		return 0;
	}
	if(2*N <= E){
		res = min(res, N*A);
	}
	if(3*N <= H){
		res = min(res, N*B);
	}
	if(N <= H && N <= E){
		res = min(res, N*C);
	}
	int temp = 0;
	if((E/2) >= 1 && (E/2) >= (3*N-H+2)/3){
		if(A < B){
			temp = min(N-1, (E/2));
		}
		else{
			temp = max(1ll, (3*N-H+2)/3);
		}
		res = min(res, temp*(A-B) + B*N);
	}
	if((H-N)/2 >= 1 && (H-N)/2 >= (N-E)){
		if(B < C){
			temp = min(N-1, (H-N)/2);
		}
		else{
			temp = max(1ll, (N-E));
		}
		res = min(res, temp*(B-C)+N*C);
	}
	if((E-N) >= 1 && (E-N) >= (N-H)){
		if(A < C){
			temp = min(N-1, E-N);
		}
		else{
			temp = max(1ll, N-H);
		}
		res = min(res, temp*(A-C) + N*C);
	}
	if(E >= 3 && H >= 4 && N >= 3){
		res = min(res, A+B+C+calculate(res, N-3, E-3, H-4, A, B, C));
	}
	return res;
}

int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, e, h, a, b, c;
		cin >> n >> e >> h >> a >> b >> c;
		int res = LLONG_MAX;
		int ans = calculate(res, n, e, h, a, b, c);
		if(ans == LLONG_MAX){
			cout << "-1\n";
		}
		else{
			cout << ans << "\n";
		}
	}
	return 0;
}
