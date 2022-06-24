#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int get();
int ask(int l, int r){
    if(l >= r) return -1;
    printf("? %d %d\n", l+1, r+1);
    fflush(stdout);
    int x = get();
    return x-1;
}
int get(){
    int x;
    scanf("%d", &x);
    return x;
}
int main(){
    int n;
    scanf("%d", &n);
    int smax = ask(0, n-1);
    int l = 0, r = n;
    if(smax == 0 || ask(0, smax) != smax){
        l = smax, r = n-1;
        while(r-l > 1){
            int mid = (l+r)/2;
            if(ask(smax, mid) == smax){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        printf("! %d\n", r+1);
        fflush(stdout);
    }
    else{
        l = 0, r = smax;
        while(r-l > 1){
            int mid = (l+r)/2;
            if(ask(mid, smax) == smax){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        printf("! %d\n", l+1);
        fflush(stdout);
    }
    return 0;
}
