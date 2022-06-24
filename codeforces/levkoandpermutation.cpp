#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    if(n == k){
        printf("-1\n");
        return 0;
    }
    printf("%d ", n-k);
    for(int i = 1; i < n-k; i++){
        printf("%d ", i);
    }
    for(int i = n-k+1; i <= n; i++){
        printf("%d ", i);
    }
    return 0;
}
