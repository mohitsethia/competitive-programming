#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int MAXN = 1e6;
vector<int> lucky;
void luckyNumbers(int x, int len){
    if(len > 8){
        return;
    }
    x = x*10 + 4;
    lucky.push_back(x);
    luckyNumbers(x, len+1);
    x /= 10;
    x = x*10 + 7;
    lucky.push_back(x);
    luckyNumbers(x, len+1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l, r;
    scanf("%lld%lld", &l, &r);
    luckyNumbers(0, 0);
    lucky.push_back(4444444444);
    sort(lucky.begin(), lucky.end());
    int i = 0;
    for(i = 0; i < (int)lucky.size(); i++){
        if(lucky[i] >= l){
            break;
        }
    }
    int ans = 0, x;
    while(l <= r){
        x = min(r, lucky[i])-l+1;
        ans += x * lucky[i];
        l = lucky[i] + 1;
        i++;
    }
    cout << ans << endl;
    return 0;
}
