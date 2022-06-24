#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, i;
        cin >> n;
        int a[n], g = 0, s = 0, b = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        for(i = 1; i < n/2 && (a[i] == a[i - 1]); i++);
        g = i;
        for(s = 0; i < n/2 && (s <= g || a[i-1] == a[i]);++i,s++);
        for(i = n/2 - 1; i > g + s && a[i] == a[i+1]; --i);
        b = i - g - s + 1;
        if(g < s && g < b && g > 0 && b > 0 && s > 0){
            cout << g << " " << s << " " << b << endl;
        }
        else
            cout << "0 0 0" << endl;
    }
    return 0;
}
