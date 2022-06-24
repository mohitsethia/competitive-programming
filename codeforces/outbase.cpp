#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    string out = "";
    while(n){
        out += (char)((n%k)+'0');
        n /= k;
    }
    reverse(out.begin(), out.end());
//    cout << out << endl;
    int countZero = 0, maxZero = 0;
    for(int i = 0; i < out.length(); i++){
        if(out[i] == '0'){
            countZero++;
            maxZero = max(maxZero, countZero);
        }
        else{
            countZero = 0;
        }
    }
    cout << (maxZero == 0 ? -1 : maxZero) << endl;
    return 0;
}
