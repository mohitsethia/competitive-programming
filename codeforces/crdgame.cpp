#include<iostream>
using namespace std;
#define int long long
int sumdigits(int x){
    int sum = 0;
    while(x > 0){
        sum += (x%10);
        x /=10;
    }
    return sum;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, chef = 0, morty = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            int sc = sumdigits(x);
            int sm = sumdigits(y);
            if(sc > sm){
                chef++;
            }
            else if(sm > sc){
                morty++;
            }
            else{
                chef++;
                morty++;
            }
        }
        if(chef > morty){
            cout << 0 << " " << chef << endl;
        }
        else if(morty > chef){
            cout << 1 << " " << morty << endl;
        }
        else{
            cout << 2 << " " << chef << endl;
        }
    }
    return 0;
}
