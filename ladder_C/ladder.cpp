//Simpler Solution

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), inc(n), dec(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n-2; i >= 0; i--){
        if(a[i] <= a[i+1]){
            inc[i] = inc[i+1]+1;
        }
        else{
            inc[i] = 0;
        }
        if(a[i] >= a[i+1]){
            dec[i] = dec[i+1]+1;
        }
        else{
            dec[i] = 0;
        }
    }
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        bool ladder = false;
        if(b <= a+inc[a] || b <= a+dec[a] || b <= (a+inc[a])+ (dec[a+inc[a]])){
            ladder = true;
        }
        printf(ladder ? "Yes\n" : "No\n");
    }
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n];
    vector<int> inc(n), dec(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        if(a[i] > a[i-1]){
            inc[i] = i;
        }
        else{
            inc[i] = inc[i-1];
        }
    }
    dec[n-1] = n-1;
    for(int i = n-2; i >= 0; i--){
        if(a[i] > a[i+1]){
            dec[i] = i;
        }
        else{
            dec[i] = dec[i+1];
        }
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        r--, l--;
        if(inc[r] <= dec[l]){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
*/
