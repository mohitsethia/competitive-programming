#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int ask(int idx){
    printf("? %d\n", idx);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

void out(int p){
    printf("! %d\n", p);
    fflush(stdout);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        out(1);
        return 0;
    }
    vector<int> a(n+2);
    a[0] = a[n+1] = 1e6;
    int l = 1, r = n;
    while(l < r){
        int mid = (l+r)/2;
        a[mid] = ask(mid);
        a[mid+1] = ask(mid+1);
        if(a[mid] < a[mid+1]){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    out(l);
    return 0;
}
