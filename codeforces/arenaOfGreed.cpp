#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int cnt = n;
        ll sum = 0;
        while(n > 0){
            if(n%2 == 0 && (n == 4 || n%4)){
                sum += n/2;
                n /= 2;
            }
            else{
                sum++;
                n--;
            }
            if(n%2){
                n--;
            }
            else{
                if(n%2 == 0 && (n == 4 || n%4)){
                    n /= 2;
                }
                else{
                    n--;
                }
            }
            //cout << n << endl;
            //cnt--;
            //if(cnt == 0){
            //    break;
            //}
        }
        cout << sum << endl;
    }
    return 0;
}
