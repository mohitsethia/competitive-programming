#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n = 4;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if((a[0] > a[2] && a[1] > a[2] && a[0] > a[3] && a[1] > a[3]) || (a[2] > a[0] && a[2] > a[1] && a[3] > a[0] && a[3] > a[1])){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}
