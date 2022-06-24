#include<iostream>
using namespace std;
int main(){
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    int a[100005] = {0};
    int count = 0;
    for(int i = k; i <= d; i += k){
        if(a[i] == 0){
            a[i]++;
            count++;
        }
    }
    for(int i = l; i <= d; i += l){
        if(a[i] == 0){
            a[i]++;
            count++;
        }
    }
    for(int i = m; i <= d; i += m){
        if(a[i] == 0){
            a[i]++;
            count++;
        }
    }
    for(int i = n; i <= d; i += n){
        if(a[i] == 0){
            a[i]++;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
