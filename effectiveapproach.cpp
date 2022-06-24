#include<iostream>
using namespace std;
#define int long long
int idx[100005] = {0};
int32_t main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        idx[x] = i;
    }
    int q, id = 0, f = 0;
    cin >> q;
    while(q--){
        int b;
        cin >> b;
        id += idx[b];
        f += (n-idx[b]+1);
//        cout << f << " ";
    }
    cout << id << " " << f << endl;
    return 0;
}
