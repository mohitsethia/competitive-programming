#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, l;
    scanf("%d%d", &n, &l);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int maxdist = 2*max(a[0], l-a[n-1]);
    for(int i = 0; i < n-1; i++){
        maxdist = max(maxdist, a[i+1]-a[i]);
    }
    printf("%.10f\n", maxdist/2.0);
    return 0;
}
