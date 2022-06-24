#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y, k;
        cin >> a >> b >> x >> y >> k;
        if(a > b){
            int diff = (b-y);
            if(diff > k){
                b -= k;
                k = 0;
            }
            else{
                b -= diff;
                k -= diff;
            }
            a -= k;
        }
        else if(a < b){
            int diff = (a-x);
            if(diff > k){
                a -= k;
                k = 0;
            }
            else{
                a -= diff;
                k -= diff;
            }
            b -= k;
        }
        else{
            int diff1 = (a-x);
            int diff2 = (b-y);
            if(diff1 > k){
                a -= k;
                k = 0;
            }
            else if(diff2 > k){
                b -= k;
                k = 0;
            }
            else{
                if(diff1 > diff2){
                    a -= diff1;
                    k -= diff1;
                    if(b-k >= y){
                        b -= k;
                    }
                    else{
                        b = y;
                    }
                }
                else if(diff1 < diff2){
                    b -= diff2;
                    k -= diff2;
                    if(a-k >= x){
                        a -= k;
                    }
                    else{
                        a = x;
                    }
                }
                else{
                    if(diff1 > k){
                        a -= k;
                        k = 0;
                    }
                    else{
                        a -= diff1;
                        k -= diff1;
                        if(b-k >= y){
                            b -= k;
                        }
                        else{
                            b = y;
                        }
                    }
                }
            }
        }
        cout << a*b << endl;
    }
    return 0;
}
