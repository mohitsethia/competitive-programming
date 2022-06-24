#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define int int64_t
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int A, B, C;
        cin >> A >> B >> C;
        cout << ((A+B+C)%9==0&&min(A, min(B, C))>=(A+B+C)/9?"YES":"NO") << endl;
    }
    return 0;
}
