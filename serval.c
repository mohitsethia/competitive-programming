#include<stdio.h>
int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    int s[n], d[n], i, temp = 0, flag = 0;
    for(i = 0; i < n; i++)
        scanf("%d%d", &s[i], &d[i]);
    for(i = 0; i < n; i++){
        if(s[i] < t){
            while(s[i] < t)
                s[i] += d[i];
}
}
    temp = s[0];
    for(i = 0; i < n; i++){
        if(temp > s[i]){
            temp = s[i];
            flag = i;
}
}
    printf("%d", flag + 1);
    return 0;
}
