/*
#include<iostream>
using namespace std;
#define INT_BITS 48
#define ll long long int
void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 
int countZeros(ll x){ 
    ll y; 
    int n = 32; 
    y = x >> 16; 
    if (y != 0) { 
        n = n - 16; 
        x = y; 
    } 
    y = x >> 8; 
    if (y != 0) { 
        n = n - 8; 
        x = y; 
    } 
    y = x >> 4; 
    if (y != 0) { 
        n = n - 4; 
        x = y; 
    } 
    y = x >> 2; 
    if (y != 0) { 
        n = n - 2; 
        x = y; 
    } 
    y = x >> 1; 
    if (y != 0) 
        return n - 2; 
    return n - x; 
} 
class shiftbit{
    public:
        int leftrotate(ll n, ll d){
            return (n << d) | (n >> (INT_BITS - d));
        }
        int rightrotate(ll n, ll d){
            return (n >> d) | (n << (INT_BITS - d));
        }
};
int main(){
    ll t;
    cin >> t;
    while(t--){
        shiftbit number;
        ll n, x;
        char c;
        cin >> n >> x >> c;
        n = n | (1 << 15);
        decToBinary(n);
        cout << endl;
        if(c == 'L'){
            int xyz = number.leftrotate(n, x);
            decToBinary(xyz);
            cout << endl;
            xyz = xyz & (~(1 << (x-1)));
            cout << xyz << endl;
        }
        else{
            int abc = number.rightrotate(n, x);
            abc = abc & (~(1 << (x-1)));
            cout << abc << endl;
        }
        
    }
    return 0;
}
*/
#include<iostream>
#include<cmath>
using namespace std;
void decToBinary(int *binaryNum, int n)  
{ 
    // array to store binary number  
  
    // counter for binary array 
    int i = 15;  
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2;  
        n = n / 2;  
        i--; 
    }   
    for(; i >= 0; i--){
        binaryNum[i] = 0;
    }
  
    // printing binary array in reverse order 
 //   for (int j = i - 1; j >= 0; j--) 
   //     cout << binaryNum[j]; 
} 
void leftshift(int *a, int m){
    for(int i = 0; i < m; i++){
        int x;
        for(int j = 0; j < 15; j++){
            if(j == 0){
                x = a[j];
            }
            a[j] = a[j+1];
        }
        a[15] = x;
    }
//    for(int i = 0; i < 16; i++){
//        cout << a[i] <<  " ";
//    }
//    cout << endl;
}
void rightshift(int *a, int m){
    for(int i = 0; i < m; i++){
        int x;
        for(int j = 15; j > 0; j--){
            if(j == 15){
                x = a[j];
            }
            a[j] = a[j-1];
        }
        a[0] = x;
    }   
//    for(int i = 0; i < 16; i++){
//        cout << a[i] << " ";
//    }
//    cout << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, ans = 0;
        char c;
        cin >> n >> m >> c;
        int *a = new int(16);
        decToBinary(a, n);
        if(c == 'L'){
            leftshift(a, m);
        }
        else{
            rightshift(a, m);
        }
        int base = 1;
        for(int i = 15; i >= 0; i--){
            ans += a[i]*base;
//            cout << a[i]*base << " ";
            base *= 2;
        }
        
        cout << ans << endl;
    }    
    return 0;
}
