#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    double n;
    cin >> n;
    int x = n*(1.08);
    if(x < 206){
        printf("Yay!");
    }
    else if(x == 206){
        printf("so-so");
    }
    else{
        printf(":(");
    }
    return 0;
}
