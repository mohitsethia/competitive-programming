#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e3 + 7;

char A[N][N];
int a[N], b[N];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
            if(A[i][j] == '*') a[i]++, b[j]++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '*'){
                ans += 1ll*(a[i]-1)*(b[j]-1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
