#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(((i+j)&1) == 0){
                int d = min(min(i+1, j+1), min(n-i, m-j));
                if(d == x) ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
