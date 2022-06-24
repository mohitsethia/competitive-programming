#include<stdio.h>
#include<string.h>
int main(){
    long long int n, m;
    scanf("%lld", &n);
    char s1[n], s2[n];
    scanf("%s", s1);
    scanf("%lld", &m);
    while(m--){
        scanf("%s", s2);
        char s3[n];
        for(int i = 0; i < strlen(s1); i++)
            s3[i] = s1[i];
        long long int p = 0;
        for(int i = 0; i < strlen(s2); i++){
            for(int j = 0; j < strlen(s3); j++){
                if(s2[i] == s3[j]){
                    s3[j] = '0';
                    if(p < j)
                        p = j;
                    break;
                }
            }
        }
        printf("%lld\n", p+1);
    }
    return 0;
}
