#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int maxx = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++){
        float a;
        cin >> a;
        float b = ceil(a/m);
        if(b >= maxx){
            maxx = b;
            idx = i;
        }
    }    
    cout << idx << endl;
    return 0;
}
