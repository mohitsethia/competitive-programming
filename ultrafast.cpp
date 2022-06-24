#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int main(){
    int t;
//    cin >> t;
//    while(t--){
        string a, b, c;
        cin >> a >> b;
        
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]){
                cout << "1";
            }
            else{
                cout << "0";
            }
/*            if(a[i] != b[i]){
                c.append("1");
            }
            else{
                c.append("0");
            }
*/
        }
//        cout << c << endl;
//    }
    return 0;
}
