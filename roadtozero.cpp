#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x, y, i, k;
        cin >> x >> y;
        cin >> i >> k;
        if(x == 0 && y == 0){ 
            cout << 0 << endl;
        }   
        else if(x == 0 && y != 0){ 
            y = abs(y);
                cout << y*i << endl;
        }   
        else if(x != 0 && y == 0){ 
            x = abs(x);
                cout << x*i << endl;
        }   
        else{
            if((x > 0 && y > 0) || (x < 0 && y < 0)){
                x = abs(x);
                y = abs(y);
                ll cost = 0;
                if(i <= k/2){
                    cout << (x*i)+(y*i) << endl;
                }   
                else{
                    if(x < y){ 
                        cost = (x * k); 
                        y = y - x;  
                        x = 0;
                    }   
                    else{
                        cost = (y * k); 
                        x = x - y;
                        y = 0;
                    }   
                    if(x > 0){ 
                            cost += (x*i);
                    }   
                    if(y > 0){ 
                            cost += (y*i);
                    }   
                    cout << cost << endl;
                }
            }
            else if(x < 0 && y > 0){
                x = abs(x);
                ll cost = (x*i) + (y*i);
                cout << cost << endl;
            }
            else if(x > 0 && y < 0){
                y = abs(y);
                ll cost = (x*i) + (y*i);
                cout << cost << endl;
            }
        }   
    }   
    return 0;
}

