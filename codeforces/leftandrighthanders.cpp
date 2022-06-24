#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", &s);
    int j = n/2;
    for(int i = 0; i < n/2; i++){
        if(s[i] == 'L' && s[j] == 'R'){
            printf("%d %d\n", i+1, j+1);
        }
        else{
            printf("%d %d\n", j+1, i+1);
        }
        j++;
    }
    return 0;
}
