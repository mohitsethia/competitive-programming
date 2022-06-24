#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int n, s, e;
    cin >> n >> s >> e;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int i = s, cnt = 1, j = -1;
    if(i == e){
        cout << 0 << endl;
        return 0;
    }
    i = a[s-1];
    while(i != (e) && j != i){
        if(i == (s)){
            cout << "-1" << endl;
            return 0;
        }
        j = i;
        i = a[i-1];
        cnt++;
    }
    if(i == e){
        cout << cnt << endl;
    }
    else if(j == i){
        cout << "-1" << endl;
    }
    return 0;
}
