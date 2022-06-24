#include<iostream>
using namespace std;
int main(){
    double n;
    cin >> n;
    double sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;
    }
    printf("%.12f", sum/n);
    return 0;
}
