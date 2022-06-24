#include<stdio.h>
#define long long int ll
int sort(ll n, ll a[]){
    ll i, j;
    for(i = 0; i < n-1; i++){
        for(j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                ll swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    return *a;
}
int main(){
    ll t, n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        int a[n], i;
    }
    return 0;
}
