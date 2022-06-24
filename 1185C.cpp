#include<iostream>
#include<algorithm>

using namespace std;

const int T = 110;
const int N = 2e5+5;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> t(N), cnt(T);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++){
        int rem = m-t[i];
        int ans = i-1;
        for(int j = 1; j < T; j++){
            int temp = min(cnt[j], rem/j);
            ans -= temp;
            rem -= j*temp;
        }
        cout << ans << " ";
        cnt[t[i]]++;
    }
    return 0;
}
