#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, t = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(t+a <= 500){
            t += a;
            printf("A");
        }
        else{
            t -= b;
            printf("G");
        }
    }
    return 0;
}
