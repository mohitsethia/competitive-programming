#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int maxx = 0, count = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        count -= a;
        count += b;
        if(count > maxx){
            maxx = count;
        }
    }
    cout << maxx << endl;
    return 0;   
}
