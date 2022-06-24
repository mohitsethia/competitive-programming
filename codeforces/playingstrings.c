#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char a[n+1], b[n+1];
        int i, count1 = 0, count2 = 0;
        scanf("%s", a);
        scanf("%s", b);
        for(i = 0; i < n; i++){
            if(a[i] == '1')
                count1++;
            if(b[i] == '1')
                count2++;
        }
        if(count1 == count2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
