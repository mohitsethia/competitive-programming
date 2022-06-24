#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m, s;
    cin >> m >> s;
    if(9*m < s || (m > 1 && s == 0)){
        cout << "-1 -1\n";
    }
    else{
        string mx = "", mn = "";
        bool canPlaceOne = false;
        int tempLen = m, sum = 0;
        if(m > 1 && (m-1)*9 >= s){
            canPlaceOne = true;
            tempLen--;
            sum++;
        }
        for(int i = 1; i <= tempLen; i++){
            for(int j = 9; j >= 0; j--){
                if(sum + j <= s){
                    mn += j+'0';
                    sum += j;
                    break;
                }
            }
        }
        reverse(mn.begin(), mn.end());
        if(canPlaceOne)
            mn = '1' + mn;
        sum = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 9; j >= 0; j--){
                if(sum + j <= s){
                    mx += j+'0';
                    sum += j;
                    break;
                }
            }
        }
        cout << mn << " " << mx << endl;
    }
    return 0;
}
