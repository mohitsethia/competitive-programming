#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a%b));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1);
    int cnt1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt1 += (a[i] == 1);
    }
    if(cnt1){
        cout << n-cnt1 << endl;
        return 0;
    }
    int ans = 1000000;
    for(int i = 1; i <= n-1; i++){
        int seg = 1000000;
        int temp = a[i];
        for(int j = i+1; j <= n; j++){
//            cout << a[i] << " " << a[j] << endl;
            temp = gcd(temp, a[j]);
//            cout << temp << " ";
            if(temp == 1){
//                cout << j << " " << i << endl;
                seg = j-i;
                break;
            }
        }
        ans = min(ans, seg+n-1);
    }
    if(ans < 1000000){
        cout << ans << endl;
    }
    else{
        cout << "-1\n";
    }
    return 0;
}
