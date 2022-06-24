#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if((((n+1)/2)-1) < k){
            cout << "-1\n";
            continue;
        }
        int i = n;
        int a[n];
        memset(a, 0, sizeof(a));
        int j = 1;
        while(k--){
            a[j] = i;
            j += 2;
            i--;
        }
        i = 1;
        for(int j = 0; j < n; j++){
            if(!a[j]){
                a[j] = i;
                i++;
            }
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
