#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[11] = {0};
  //      vector<pair<int, int> > v;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            b[x]++;
 //           cout << b[x] << endl;
        }
        int cnt = 0, mn = 0, fi = 0;
        for(int i = 1; i <= 10; i++){
            int freq = b[i];
//            cout << freq << endl;
            if(freq == 0){
                continue;
            }
            cnt = 0;
            for(int j = 1; j <= 10; j++){
                if(i != j && b[j] == freq){
                    cnt++;
                }
                
            }
            if(cnt > mn){
                mn = cnt;
                fi = freq;
            }
            else if(cnt == mn){
                if(freq < fi){
                    fi = freq;
                }
            }
 //           cout << cnt << " " << fi << endl;
        }
        cout << fi << endl;
    }
    return 0;
}
