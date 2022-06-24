#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

const int N = 1e5+1;

int a[N], b[N];
map<int, int> p;

int32_t main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
         cin >> b[i];
         if(a[i] == b[i]) cnt++;
         p[b[i]]++;
    }
    int m;
    cin >> m;
    int ans = 1;
    for(auto i: p){
        for(int j = 1; j <= i.second; j++){
            int t = j;
            while(t%2 == 0 && cnt){
                t /= 2;
                cnt--;
            }
            ans = ans*t % m;
        }
    }
    cout << ans%m << "\n";
    return 0;
}
