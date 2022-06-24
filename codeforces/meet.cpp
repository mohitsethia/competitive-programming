#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
void solve(){
    string t_t, p;
    cin >> t_t >> p;
    int n;
    scanf("%d", &n);
    if(p == "PM"){
        if(!(t_t[0] == '1' && t_t[1] == '2')){
            int temp = t_t[0] - '0';
            temp *= 10;
            temp += t_t[1] - '0';
            temp += 12;
            t_t[1] = (temp%10)+'0';
            t_t[0] = (temp/10)+'0';
        }
    }
    else{
        if(t_t[0] == '1' && t_t[1] == '2'){
            int temp = t_t[0] - '0';
            temp *= 10;
            temp += t_t[1] - '0';
            temp -= 12;
            t_t[1] = (temp%10) + '0';
            t_t[0] = (temp/10) + '0';
        }
    }
    string a, b, c, d;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        if(b == "PM"){
            if(!(a[0] == '1' && a[1] == '2')){
                int temp = a[0] - '0';
                temp *= 10;
                temp += a[1] - '0';
                temp += 12;
                a[1] = (temp%10) + '0';
                a[0] = (temp/10) + '0';
            }
        }
        else{
            if(a[0] == '1' && a[1] == '2'){
                int temp = a[0] - '0';
                temp *= 10;
                temp += a[1] - '0';
                temp -= 12;
                a[1] = (temp%10) + '0';
                a[0] = (temp/10) + '0';
            }
        }
        if(d == "PM"){
            if(!(c[0] == '1' && c[1] == '2')){
                int temp = c[0] - '0';
                temp *= 10;
                temp += c[1] - '0';
                temp += 12;
                c[1] = (temp%10) + '0';
                c[0] = (temp/10) + '0';
            }   
        }   
        else{
            if(c[0] == '1' && c[1] == '2'){
                int temp = c[0] - '0';
                temp *= 10;
                temp += c[1] - '0';
                temp -= 12;
                c[1] = (temp%10) + '0';
                c[0] = (temp/10) + '0';
            }   
        }   
        if(t_t >= a && t_t <= c){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
