#include<stdio.h>
#include<math.h>
#define ll long long int 
int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll a, f = 0;
        scanf("%lld", &a);
        if(a == 2){
            printf("YES\n");
            continue;
        }
        if(a != 2 && a % 2 == 0){
            printf("NO\n");
            continue;
        }
        for(ll i = 3; i <= sqrt(a); i+=2){
            if(a % i == 0){
                f = 1;
                break;
            }
        }
        if(f == 1){ 
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
