#include<iostream>
#include<algorithm>

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int grid[n][m];
        for(int i = 0 ;i < n;i++){
			for(int j = 0 ;j < m;j++){
				cin >> grid[i][j];
			}
		}
		long long ans = 0;
		for(int i = 0 ;i < (n + 1) / 2;i++){
			for(int j = 0 ;j < (m + 1) / 2;j++){
				vector< int > v;
				v.push_back(grid[i][j]);
				if(i != n - i - 1)
					v.push_back(grid[n - i - 1][j]);
				if(m - j - 1 != j)
					v.push_back(grid[i][m - j - 1]);
				if(i != n - i - 1 && j != m - j - 1);
				v.push_back(grid[n - i - 1][m - j - 1]);
				sort(v.begin(),v.end());
				int mid = (int)v.size() / 2;
				for(int j = 0 ;j < (int)v.size();j++){
					ans += abs(v[j] - v[mid]);
				}
			}
		}
        cout << ans << "\n";
    }
    return 0;
}
