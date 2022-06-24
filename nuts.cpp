#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > 10){
            sum += (x-10);
        }
    }
    cout << sum << endl;
    return 0;
}
