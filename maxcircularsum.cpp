#include<iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], i, cs1 = 0, cs2 = 0, ms = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        for(i = 0; i < n; i++){
            if(cs1 < 0){
                cs1 = 0;
            }
            cs1 += a[i];
            if(ms < cs1){
                ms = cs1;
            }
        }
        cs1 = ms;
		ms = 0;
        for(i = 0; i < n; i++){
            a[i] = -a[i];
        }
        for(i = 0; i < n; i++){
            cs2 += a[i];
			if(cs2 < 0){
				cs2 = 0;
			}
            if(ms < cs2){
                ms = cs2;
            }
        }
        cs2 = ms;
        cout << cs1 + cs2 << endl;        
    }
	return 0;
}
