#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a;
    while(scanf("%d", &a)){
        if(a == 0){
            break;
        }
        cout << (a*(a+1)*(2*a + 1))/6 << endl;
    }
    return 0;
}
