#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define endl '\n'
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll groups = m+1;
        ll group_zeroes = (n-m)/groups;
        ll sizeOfExtra_zeroes = (n-m)%groups;
        ll sizeOf_groupZeroes = groups - sizeOfExtra_zeroes;
        ll extraZeroes = group_zeroes + 1;
        ll total_subString = (n * (n+1)/2);
        ll extraZeroesSubString = (extraZeroes * (extraZeroes+1)/2)*sizeOfExtra_zeroes;
        ll groupZeroesSubString = (group_zeroes * ( group_zeroes+1)/2)*sizeOf_groupZeroes;
        ll max_value = total_subString - extraZeroesSubString - groupZeroesSubString;
        cout << max_value << endl;
    }
    return 0;
}
