#include<iostream>
#include<algorithm>
using namespace std;
int main(){
        int n, q;
        cin >> n >> q;
        int a[51] = {0};
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(!a[x])
                a[x] = i;
        }
        while(q--){
            int w;
            cin >> w;
            cout << a[w] << " ";
            for(int i = 1; i < 51; i++){
                if(a[i] < a[w])
                    a[i]++;
            }
            a[w] = 1;
        }
    return 0;
}
