#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    printf("? 1 2\n");
    fflush(stdout);
    int s1, s2, s3;
    scanf("%d", &s1);
    printf("? 1 3\n");
    fflush(stdout);
    scanf("%d", &s2);
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &s3);
    vector<int> a(n);
    a[0] = s2-s3;
    a[1] = s1-a[0];
    a[2] = s2-s1;
    int i = 3;
    for(; i < n; i++){
        printf("? %d %d\n", i, i+1);
        fflush(stdout);
        int sum;
        scanf("%d", &sum);
        a[i] = sum-a[i-1];
    }
    printf("! ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    fflush(stdout);
    exit(0);
    return 0;
}
