#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        for(int i = n; i >= 1; i--){
            if(sum % i == 0){
                int needsum = sum/i, currsum = 0, ok = 1;
                for(int j = 0; j < n; j++){
                    currsum += a[j];
                    if(currsum > needsum){
                        ok = 0;
                        break;
                    }
                    else if(currsum == needsum){
                        currsum = 0;
                    }
                }
                if(ok){
                    cout << n-i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
