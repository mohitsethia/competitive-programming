
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int checkdigit(int x){
    int i, j = 0, a[100000], k = 0, ch = 0;
    for(i = x % 10; i > 0; i = x / 10){
        a[k] = i;
        k++;
    }
    for(i = 0; i < k - 1; i++){
        for(j = i + 1; j < k; j++){
            if(a[i] == a[j]){
                ch = 1;
            }
        }
    }
    if(ch == 0){
        return true;
    }
    else
        return false;
}
int main(){
    int r, l, i, j = 0, max[r-l+1], maximum = 0;
    cin >> l >> r;
    for(i = r-1; i > l; i--){
        if((r-i)*(i-l) > maximum){
            if(checkdigit(i)){
                maximum = (r-i)*(i-l);
                max[j] = i;
                j++;
            }
        }
    }
    cout << max[j];
    return 0;
}
