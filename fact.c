#include<stdio.h>
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p){
        return os<<'('<<p.F<< ","<<p.S<<')';
}
int main(){
    int t, n;
    long long int count = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n == 0)
            cout << 1;
        	//printf("1");
        else if(n > 0){
            for(int i = 1; i <= n; i++){
    	        count = i * count;
            }
            printf("%lld\n", count);
        }
    }
    return 0;
}
