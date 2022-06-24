#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        if(u <= n-2 && d <= n-2 && l <= n-2 && r <= n-2){
            puts("YES");
            continue;
        }
        int up = u, down = d, left = l, right = r;
        if(u == n){
            right--, left--;
        }
        if(d == n){
            right--, left--;
        }
        if(r == n){
            up--, down--;
        }
        if(l == n){
            up--, down--;
        }
        if(u == n-1){
            right > left ? right-- : left--;
        }
        if(d == n-1){
            right > left ? right-- : left--;
        }
        if(r == n-1){
            up > down ? up-- : down--;
        }
        if(l == n-1){
            up > down ? up-- : down--;
        }
        if(right < 0 || up < 0 || down < 0 || left < 0){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
    return 0;
}
