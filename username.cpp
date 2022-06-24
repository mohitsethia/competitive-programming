#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int minsofar = x, maxsofar = x, count = 0;
    for(int i = 1; i < n; i++){
        int per;
        cin >> per;
        if(per > maxsofar){
            maxsofar = per;
            count++;
        }
        if(per < minsofar){
            minsofar = per;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
